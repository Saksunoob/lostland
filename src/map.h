#pragma once

#include <unordered_map>
#include <cmath>

#include "engine/core.h"
#include "engine/game_objects/sprites.h"
#include "engine/game_objects/transform.h"

using namespace Engine::GameObjects;

enum Tile {
	STONE,
	SAND,
	DIRT,
	GRASS
};

class Map;

struct Chunk {
	std::vector<Tile> tiles;
	static const unsigned int CHUNK_SIZE = 64;
	GameObject *object;

	Chunk(Map* map, IVec2 pos);
	void setTile(IVec2 pos, Tile tile);
	Tile getTile(IVec2 pos);
private:
	static bool posInBounds(IVec2 pos);
};

class PerlinNoise {
	static double interpolate(double a, double b, double weight);
	static Vec2 randomGradient(IVec2, unsigned);
public:
	static double perlin(Vec2 pos, unsigned seed);
};

class Map : public Component {
	std::unordered_map<IVec2, Chunk*> chunks;
	
	IVec2 getChunk(IVec2 pos);
public:
	TextureAtlas atlas;
	Texture blend_mask;
	unsigned int seed;


	Map(unsigned int seed, TextureAtlas atlas, Texture blend_mask) : chunks(std::unordered_map<IVec2, Chunk*>()), atlas(atlas), seed(seed), blend_mask(blend_mask) {};

	Chunk* generateChunk(IVec2 pos);
	void setTile(IVec2 pos, Tile tile);
	Tile getTile(IVec2 pos);

	~Map();
};