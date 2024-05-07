#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Barco
{
	private:
		Texture texture;
		Sprite sprite;

	public:
		//Constructor
		Barco(const string&);

		//Metodo para setScale
		void setScale(float, float);
		
		//Metodo para setPosition
		void setPosition(float, float);

		// Método para obtener la posición del barco
		Vector2f getPosition() const;

		//Metodo para dibujar
		void drawShip(RenderWindow&);

		//Metodos para acceder a la textura y sprite
		Texture& getTexture();
		Sprite& getSprite();

};
