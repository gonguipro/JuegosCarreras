#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Background
{
	private:
		Texture texture;
		Sprite sprite;

	public:	
		Background(const string&);

		void velocidadFondo(float velocidadFondo);

		//Metodo para setScale
		void setScale(float, float);

		//Metodo para dibujar
		void drawBackground(RenderWindow&);

		//Metodos para acceder a la textura y sprite
		Texture& getTexture();
		Sprite& getSprite();

};
