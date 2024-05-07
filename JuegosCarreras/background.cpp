#include "background.h"


//Background
Background::Background(const string& backgroundPath)
{
	if (!texture.loadFromFile(backgroundPath))
	{
		cout << "Error al cargar el fondo" << endl;
	}
	sprite.setTexture(texture);
}

void Background::velocidadFondo(float _velocidadFondo)
{
	sprite.move(_velocidadFondo, 0);
}

void Background::setScale(float scaleX, float scaleY) {
	sprite.setScale(scaleX, scaleY);
};

void Background::drawBackground(RenderWindow& window) {
	window.draw(sprite);
}


Texture& Background::getTexture() {
	return texture;
}

Sprite& Background::getSprite() {
	return sprite;
}
