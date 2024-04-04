#include "map.h"

Chunk::Chunk(Map* map) : tiles(std::vector<Tile>(CHUNK_SIZE* CHUNK_SIZE, NONE)), object() {
	Transform transform;
	TileMapRenderer renderer(map->atlas, CHUNK_SIZE, CHUNK_SIZE, 64, 64);
	transform.scale = Vec2(0.25, 0.25);	
	for (int i = 0; i < CHUNK_SIZE * CHUNK_SIZE; i++) {
		tiles[i] = static_cast<Tile>(i % 4);
	}
	renderer.tiles = reinterpret_cast<unsigned int*>(tiles.data());
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
		object->get_component<TileMapRenderer>()->tiles = reinterpret_cast<unsigned int*>(tiles.data());
	}
}

Tile Chunk::getTile(IVec2 pos) {
	if (posInBounds(pos)) {
		return tiles[pos.y * CHUNK_SIZE + pos.x];
	}
	return NONE;
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
		Chunk* chunk = new Chunk(this);
		chunk->object->get_component<Transform>()->position = pos * Chunk::CHUNK_SIZE * 16;
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
		return NONE;

	return chunks[chunk_pos]->getTile((pos + Chunk::CHUNK_SIZE) % Chunk::CHUNK_SIZE);
}

Map::~Map() {
	for (auto chunk : chunks) {
		delete chunk.second;
	}
}