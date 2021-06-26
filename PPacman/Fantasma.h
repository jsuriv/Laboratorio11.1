#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <algorithm>

#include "GameActor.h"
#include "Texture.h"
#include "Tile.h"
#include "TileGraph.h"
#include "MoveDirection.h"

#include "PathFinder.h"
#include "Pacman.h"
#include "GameObjectType.h"

using namespace std;

enum GameFantasmaType {
	FANTASMA_CLASICO,
	FANTASMA_GALACTICO
};


class Fantasma : public GameActor {
protected:
	GameFantasmaType tipoFantasma;

	vector<Tile*> camino;
	SDL_Point lastPacmanPos;

public:

	GameFantasmaType returnGameFantasmaType() { return tipoFantasma; }
public:
	//Constructores y destructores
	Fantasma(Tile* _tile, Texture* _texture);
	void setTileActual(Tile* _tileNuevo);

	// Actualizar datos fantasma
	static bool avoidInPathFinder(Tile* _tile);
	bool hasPositionChanged(SDL_Point firstPos, SDL_Point secondPoint);

	void update();
	void render();
	void deleteGameObject() override;
	void handleEvent(SDL_Event* event) {};
};