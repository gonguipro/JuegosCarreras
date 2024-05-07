#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class EndGame {
private:
    Texture copaTexture;
    Sprite copaSprite;
    Texture endBackgroundTexture;
    Sprite endBackgroundSprite;
    Font font;
    Text textoGanador;

public:
    EndGame(const string& copaPath, const string& endBackgroundPath, const string& fontPath);

    void mostrarVentanaFinal(RenderWindow&, const string&);
};

