#include "Fruta.h"
#include <iostream>

using namespace std;

Fruta::Fruta(Tile* _tile, Texture* _texture) : GameActor(_texture)
{
	tileActual = _tile;
	if (tileActual != nullptr) {
		tileActual->setFruta(nullptr);
		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;

		ancho = Tile::anchoTile;
		alto = Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

	tipoFruta = TIPO_FRUTA_FRUTILLA;

	visible = false;

	tiempoVisible = 100;
	tiempoInvisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoInvisible = 0;
	numeroFrutaVisible = 0;
}

void Fruta::update()
{
	if (contadorTiempoVisible >= tiempoVisible) {
		visible = false;
		if (contadorTiempoInvisible >= tiempoInvisible) {
			/*posicionX = 1 + rand() % tileGraph->anchoPantalla;
			posicionY = 1 + rand() % tileGraph->altoPantalla;*/
			contadorTiempoVisible = 0;
			contadorTiempoInvisible = 0;
			visible = true;
			//numeroFrutaVisible = rand() % frutasTextures.size();
			numeroFrutaVisible = rand() % 4;
		}
		else {
			contadorTiempoInvisible++;
			//contadorTiempoNoVisible = contadorTiempoNoVisible + 1;
		}
	}
	else {
		contadorTiempoVisible++;
	}
}
void Fruta::deleteGameObject()
{
	// Calling the base function
	GameObject::deleteGameObject();

	tileActual->setFruta(nullptr);
}