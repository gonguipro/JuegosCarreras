#include "barcos.h"

using namespace std;
using namespace sf;

Barco::Barco(const string& texturePath)
{
	if (!texture.loadFromFile(texturePath))
	{
		cout << "Error al cargar la foto del barco." << endl;
	}
	sprite.setTexture(texture);
};

void Barco::setScale(float scaleX, float scaleY) {
	sprite.setScale(scaleX, scaleY);
};

void Barco::setPosition(float x, float y) {
	sprite.setPosition(x, y);
}

void Barco::drawShip(RenderWindow& window) {
	window.draw(sprite);
}

Vector2f Barco::getPosition() const
{
	return sprite.getPosition();
}

Texture& Barco::getTexture() {
	return texture;
}

Sprite& Barco::getSprite() {
	return sprite;
}






