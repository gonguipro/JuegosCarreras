#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class Dado
{
	private:
		int valorSeleccionado;
		Texture texture;
		vector <Sprite> caras;

	public:
		//Constructor
		Dado(const string&);

		//Metodo para setScale
		void setScale(float, float);

		//Metodo para setPosition
		void setPosition(float, float);

		// Método para lanzar el dado y obtener un valor aleatorio
		int lanzarDado();

		// Método para obtener el valor actual del dado
		int getValorSeleccionado();

		//Dibujar dado
		void drawDice(RenderWindow&);

		//Metodos para acceder a la textura y sprite
		Texture& getTexture();
		Sprite& getSprite();
};