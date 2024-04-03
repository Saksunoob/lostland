#pragma once

#include "engine/game_objects/game_object.h"
#include "engine/game_objects/sprites.h"
#include "engine/game_objects/transform.h"
#include "engine/core/engine.h"

using namespace Engine::GameObjects;

enum Tile {
	NONE,
	STONE,
	DIRT,
	GRASS
};

struct Chunk {
	std::vector<Tile> tiles;
	static const unsigned int CHUNK_SIZE = 16;
	GameObject object;

	Chunk(Texture atlas);
	void setTile(IVec2 pos, Tile tile);
	Tile getTile(IVec2 pos);
private:
	static bool posInBounds(IVec2 pos);
};

class Map : public Component {
	std::unordered_map<IVec2, Chunk*> chunks;
	Texture atlas;

	IVec2 getChunk(IVec2 pos);
public:
	Map(Texture atlas) : chunks(std::unordered_map<IVec2, Chunk*>()), atlas(atlas) {};

	Chunk* generateChunk(IVec2 pos);
	void setTile(IVec2 pos, Tile tile);
	Tile getTile(IVec2 pos);

	~Map();
};