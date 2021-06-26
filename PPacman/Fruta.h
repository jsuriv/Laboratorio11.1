#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include "GameActor.h"
#include "Texture.h"
#include "TileGraph.h"
#include "Tile.h"

using namespace std;

enum TipoFruta {
	TIPO_FRUTA_GUINDA,
	TIPO_FRUTA_PLATANO,
	TIPO_FRUTA_NARANJA,
	TIPO_FRUTA_FRUTILLA,
	TIPO_FRUTA_MAXIMO
};

class Fruta : public GameActor {
protected:

	TipoFruta tipoFruta;

	int tiempoVisible;
	int tiempoInvisible;

	int contadorTiempoVisible;
	int contadorTiempoInvisible;
	int numeroFrutaVisible;
public:

	Fruta(Tile* _tile, Texture* _texture);

	//Metodos accesores

	TipoFruta getTipoFruta() { return tipoFruta; }
	int getTiempoVisible() { return tiempoVisible; }
	int getTiempoInvisible() { return tiempoInvisible; }

	void setTipoFruta(TipoFruta _tipoFruta) { tipoFruta = _tipoFruta; }
	void setTiempoVisible(int _tiempoVisible) { tiempoVisible = _tiempoVisible; }
	void setTiempoInvisible(int _tiempoInvisible) { tiempoInvisible = _tiempoInvisible; }
	void setTileActual(Tile* _tileNuevo) {};

	// Metodos varios
	// Mostrar u ocultar la fruta
	void update();
	void deleteGameObject();
	void handleEvent(SDL_Event* event) {};
};