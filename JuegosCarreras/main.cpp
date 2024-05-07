#include "background.h"
#include "endgame.h"
#include "turnos.h"

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1000, 800), "Carrera de Barcos");

    // Crear instancia del barco1
    Barco barco1("imagenes/barco.png");

    // Escalar y posicionar el barco1 
    barco1.setScale(0.5f, 0.5f);
    barco1.setPosition(0.0f, 420.0f);


    //Crear instancia del barco2
    Barco barco2("imagenes/barco.png");

    //Escalar y posicionar el barco2
    barco2.setScale(0.5f, 0.5f);
    barco2.setPosition(0.0f, 500.0f);

    // Crear instancia del dado
    Dado dado("imagenes/dado.png");

    // Escalar y posicionar el dado
    dado.setScale(0.7f, 0.7f);
    dado.setPosition(20.0f, 680.0f);

    //Crear la instancia para el paisaje
    Background background("imagenes/fondo.png");
    background.setScale(1.0f, 1.0f);

    // Crear instancia de EndGame
    EndGame endGame("imagenes/copa.png", "imagenes/endgamebackground.png", "imagenes/font.ttf");

    // Crear instancia de Turnos
    Turnos turnos(barco1, barco2, dado, window); 

    // Velocidad del fondo
    float velocidadFondo = -0.01f;

    while (window.isOpen())
    {
        // Procesar eventos
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            // Verificar el turno de los barcos utilizando la clase Turnos
            turnos.verificarTurnos(event);
        }

        // Mover el fondo
        background.velocidadFondo(velocidadFondo);

        window.clear();
        background.drawBackground(window);
        barco1.drawShip(window);
        barco2.drawShip(window);
        dado.drawDice(window);
        window.display();

        // Verificar si algún barco ha ganado utilizando la clase Turnos
        if (turnos.haGanadoAlgunBarco())
        {
            // Mostrar ventana final del juego utilizando la clase EndGame
            endGame.mostrarVentanaFinal(window, turnos.obtenerNombreGanador());
        }
    }

    return 0;
}
