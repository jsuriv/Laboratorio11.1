#include "MapGenerator.h"

MapGenerator::MapGenerator(TileGraph* _tileGraph, TextureManager* _textureManager, int _anchoPantalla, int _altoPantalla)
{
	tileGraph = _tileGraph;
	textureManager = _textureManager;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
}

bool MapGenerator::load(string path)
{
	// Crea un flujo a un archivo
	fstream file;

	// Abre el archivo y verifica si tuvo exito
	file.open(path.c_str(), ios::in);

	// Retorna false si falla la apertura del archivo
	if (file.is_open() == false)
		return false;

	string line;

	int x = 0;
	int y = 0;

	// Lee el archivo linea por linea
	while (getline(file, line)) {
		// Divide la linea leida y la guarda en un vector de caracteres
		vector<char> chars(line.begin(), line.end());

		for (unsigned int x = 0; x < chars.size(); x++) {
			GameObject* objetoNuevo = nullptr;
			Fantasma* objetoFantasmaClonado = nullptr;
			Tile* tileNuevo = tileGraph->getTileEn(x, y);

			// Se verifica que letra es la que se lee y en funcion a ello se crea un tipo de objeto
			switch (chars[x])
			{
			case 'x':
				objetoNuevo = new Pared(tileNuevo, textureManager->getTextura("pared_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(8);
				break;
			case '.':
				objetoNuevo = new Moneda(tileNuevo, textureManager->getTextura("moneda_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(4);
				break;
			case 'p':
				objetoNuevo = new Pacman(tileNuevo, textureManager->getTextura("pacman_clasico"));
				((GameActor*)objetoNuevo)->setFramesAnimacion(textureManager->getFramesAnimacion("pacman_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(2);
				break;
			case 'm':
				objetoNuevo = new MsPacman(tileNuevo, textureManager->getTextura("mspacman_clasico"));
				((GameActor*)objetoNuevo)->setFramesAnimacion(textureManager->getFramesAnimacion("pacman_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(2);
				break;

			case 'a':
				objetoNuevo = new Fantasma(tileNuevo, textureManager->getTextura("fantasma_clasico1"));
				((GameActor*)objetoNuevo)->setFramesAnimacion(textureManager->getFramesAnimacion("fantasma_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(2);
				((GameActor*)objetoNuevo)->setVelocidad(1);
				break;
			case 'b':
				objetoNuevo = new Fantasma(tileNuevo, textureManager->getTextura("fantasma_clasico2"));
				((GameActor*)objetoNuevo)->setFramesAnimacion(textureManager->getFramesAnimacion("fantasma_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(3);
				((GameActor*)objetoNuevo)->setVelocidad(2);
				break;
			case 'c':
				objetoNuevo = new Fantasma(tileNuevo, textureManager->getTextura("fantasma_clasico3"));
				((GameActor*)objetoNuevo)->setFramesAnimacion(textureManager->getFramesAnimacion("fantasma_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(2);
				((GameActor*)objetoNuevo)->setVelocidad(2.5);
				break;
			case 'd':
				objetoNuevo = new Fantasma(tileNuevo, textureManager->getTextura("fantasma_clasico4"));
				((GameActor*)objetoNuevo)->setFramesAnimacion(textureManager->getFramesAnimacion("fantasma_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(2);
				((GameActor*)objetoNuevo)->setVelocidad(1.5);
				break;
			case 'f':
				objetoNuevo = new Fruta(tileNuevo, textureManager->getTextura("fruta_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(4);
				break;
			}

			// If the object was created, add it to the vector
			if (objetoNuevo != nullptr) {
				vectorObjetosJuego.push_back(objetoNuevo);
			}
		}

		y++;
	}

	// Close the file
	file.close();

	return true;
}

void MapGenerator::populate(std::vector<GameObject*>& _vectorObjetosJuegoGM)
{
	for (auto ivoj = vectorObjetosJuego.begin(); ivoj != vectorObjetosJuego.end(); ++ivoj) {
		_vectorObjetosJuegoGM.push_back(*ivoj);
	}

}