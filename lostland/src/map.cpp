#include "map.h"

Chunk::Chunk(Map* map, IVec2 pos) : tiles(std::vector<Tile>((CHUNK_SIZE+2)* (CHUNK_SIZE+2), static_cast<Tile>(0))), object() {
	Transform transform;
	TileMapRenderer renderer(map->atlas, IVec2(CHUNK_SIZE), map->blend_mask);
	transform.scale = Vec2(1.0, 1.0);

	for (int i = 0; i < (CHUNK_SIZE+2)*(CHUNK_SIZE+2); i++) {
		int c_x = i % (CHUNK_SIZE+2) - 1;
		int c_y = i / (CHUNK_SIZE+2) - 1;

		double x = (double)(c_x + (int)CHUNK_SIZE * pos.x) / 128;
		double y = (double)(c_y + (int)CHUNK_SIZE * pos.y) / 128.;

		double height = PerlinNoise::perlin(Vec2(x, y), map->seed);

		if (height <= -0.25) {
			tiles[i] = Tile::STONE;
		}
		else if (height <= 0) {
			tiles[i] = Tile::SAND;
		}
		else if (height <= 0.25) {
			tiles[i] = Tile::DIRT;
		}
		else {
			tiles[i] = Tile::GRASS;
		}
	}
	renderer.setTiles(reinterpret_cast<unsigned int*>(tiles.data()));
	object = map->object->scene->instatiate(map->object);
	object->attach(transform);
	object->attach(renderer);
};

bool Chunk::posInBounds(IVec2 pos) {
	return pos.x >= 0 && pos.y >= 0 && pos.x < CHUNK_SIZE && pos.y < CHUNK_SIZE;
}

void Chunk::setTile(IVec2 pos, Tile tile) {
	if (posInBounds(pos)) {
		tiles[pos.y * CHUNK_SIZE + pos.x] = tile;
		object->get_component<TileMapRenderer>()->setTiles(reinterpret_cast<unsigned int*>(tiles.data()));
	}
}

Tile Chunk::getTile(IVec2 pos) {
	if (posInBounds(pos)) {
		return tiles[pos.y * CHUNK_SIZE + pos.x];
	}
	return static_cast<Tile>(0);
}

/// <summary>
/// Gets the chunk coordinates of a tile
/// </summary>
/// <param name="pos">Tile position</param>
/// <returns>Chunk coordinate</returns>
IVec2 Map::getChunk(IVec2 pos) {
	auto floorToChunk = [](int x) {return x >= 0 ? x / (int)Chunk::CHUNK_SIZE : (x - (int)Chunk::CHUNK_SIZE + 1) / (int)Chunk::CHUNK_SIZE; };

	return IVec2(floorToChunk(pos.x), floorToChunk(pos.y));
}

/// <summary>
/// Generates a new chunk in the map. If it already exists, does nothing.
/// </summary>
/// <param name="pos">Chunk coordinates of the chunk to be generated</param>
Chunk* Map::generateChunk(IVec2 pos) {
	if (chunks.find(pos) == chunks.end()) {
		Chunk* chunk = new Chunk(this, pos);
		chunk->object->get_component<Transform>()->position = pos * Chunk::CHUNK_SIZE * 64;
		chunks[pos] = chunk;
	}
	return chunks[pos];
}
void Map::setTile(IVec2 pos, Tile tile) {
	IVec2 chunk_pos = getChunk(pos);
	Chunk *chunk = generateChunk(chunk_pos);
	chunk->setTile((pos+Chunk::CHUNK_SIZE)%Chunk::CHUNK_SIZE, tile);
}
Tile Map::getTile(IVec2 pos) {
	IVec2 chunk_pos = getChunk(pos);

	if (chunks.find(chunk_pos) == chunks.end())
		return static_cast<Tile>(0);

	return chunks[chunk_pos]->getTile((pos + Chunk::CHUNK_SIZE) % Chunk::CHUNK_SIZE);
}

Map::~Map() {
	for (auto chunk : chunks) {
		delete chunk.second;
	}
}

/// <summary>
/// Generates a pseudorandom hash
/// </summary>
/// <param name="pos"></param>
/// <param name="seed"></param>
/// <returns></returns>
Vec2 PerlinNoise::randomGradient(IVec2 pos, unsigned seed) {
	// No precomputed gradients mean this works for any number of grid coordinates
	const unsigned w = 8 * sizeof(unsigned);
	const unsigned s = w / 2;
	unsigned a = pos.x ^ seed, b = pos.y ^ seed;
	a *= 3284157443;

	b ^= a << s | a >> w - s;
	b *= 1911520717;

	a ^= b << s | b >> w - s;
	a *= 2048419325;
	double random = a * (3.14159265 / ~(~0u >> 1)); // in [0, 2*Pi]

	// Create the vector from the angle
	Vec2 v;
	v.x = sin(random);
	v.y = cos(random);

	return v;
}

double PerlinNoise::interpolate(double a, double b, double weight) {
	return (b - a) * (3.0 - weight * 2.0) * weight * weight + a;
}


double PerlinNoise::perlin(Vec2 pos, unsigned seed) {
	// Determine grid cell corner coordinates
	int x0 = std::floor(pos.x);
	int y0 = std::floor(pos.y);
	int x1 = x0 + 1;
	int y1 = y0 + 1;

	// Compute Interpolation weights
	double sx = pos.x - (double)x0;
	double sy = pos.y - (double)y0;

	// Compute and interpolate top two corners
	double n0 = randomGradient(IVec2(x0, y0), seed).dot(pos - Vec2(x0, y0));
	double n1 = randomGradient(IVec2(x1, y0), seed).dot(pos - Vec2(x1, y0));
	double ix0 = interpolate(n0, n1, sx);

	// Compute and interpolate bottom two corners
	n0 = randomGradient(IVec2(x0, y1), seed).dot(pos - Vec2(x0, y1));
	n1 = randomGradient(IVec2(x1, y1), seed).dot(pos - Vec2(x1, y1));
	double ix1 = interpolate(n0, n1, sx);

	// Final step: interpolate between the two previously interpolated values, now in y
	double value = interpolate(ix0, ix1, sy);
	

	return value;
}