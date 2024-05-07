#include "endgame.h"

EndGame::EndGame(const string& copaPath, const string& endBackgroundPath, const string& fontPath) {
    if (!copaTexture.loadFromFile(copaPath)) {
        cout << "Error al cargar la foto de la copa" << endl;
    }
    copaSprite.setTexture(copaTexture);
    copaSprite.setPosition(230.0f, 120.0f);

    if (!endBackgroundTexture.loadFromFile(endBackgroundPath)) {
        cout << "Error al cargar el fondo de la ventana final" << endl;
    }
    endBackgroundSprite.setTexture(endBackgroundTexture);

    if (!font.loadFromFile(fontPath)) {
        cout << "Error al cargar la fuente." << endl;
    }
    textoGanador.setFont(font);
    textoGanador.setCharacterSize(100);
    textoGanador.setFillColor(Color::Black);
}

void EndGame::mostrarVentanaFinal(RenderWindow& window, const string& nombreGanador) {
    textoGanador.setString(nombreGanador + " HA GANADO!");
    textoGanador.setPosition(130.0f, 20.0f);

    window.clear();
    window.draw(endBackgroundSprite);
    window.draw(textoGanador);
    window.draw(copaSprite);
    window.display();

    sleep(seconds(4));

    window.close();
}
