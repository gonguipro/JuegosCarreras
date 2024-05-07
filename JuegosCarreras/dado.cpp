#include "dado.h"

Dado::Dado(const string& texturePath)
{
    if (!texture.loadFromFile(texturePath))
    {
        cout << "Error al cargar la textura del dado." << endl;
        return;
    }

    // Obtener el tamaño de la textura del dado
    Vector2u sizeDado = texture.getSize();
    int width = sizeDado.x / 3;
    int height = sizeDado.y / 2;

    // Crear los sprites para cada cara del dado
    for (int i = 0; i < 6; i++)
    {
        int row = i / 3; // Fila en la textura
        int col = i % 3; // Columna en la textura

        IntRect rect(col * width, row * height, width, height);
        Sprite cara(texture, rect);
        caras.push_back(cara);
    }

    // Inicializar el valor seleccionado del dado
    valorSeleccionado = 1;
}

void Dado::setScale(float scaleX, float scaleY)
{
    for (Sprite& cara : caras)
    {
        cara.setScale(scaleX, scaleY);
    }
}

void Dado::setPosition(float x, float y)
{
    for (Sprite& cara : caras)
    {
        cara.setPosition(x, y);
    }
}

void Dado::drawDice(RenderWindow& window)
{
    window.draw(caras[valorSeleccionado - 1]);
}

int Dado::lanzarDado()
{
    // Generar un número aleatorio entre 1 y 6
    valorSeleccionado = rand() % 6 + 1;
    return valorSeleccionado;
}

int Dado::getValorSeleccionado()
{
    return valorSeleccionado;
}
