#include "turnos.h"

Turnos::Turnos(Barco& _barco1, Barco& _barco2, Dado& _dado, RenderWindow& _window)
    : barco1(_barco1), barco2(_barco2), dado(_dado), window(_window), barco1LlegoAlBorde(false), barco2LlegoAlBorde(false) {}

void Turnos::verificarTurnos(Event event) {
    if (event.type == Event::KeyPressed && event.key.code == Keyboard::A && !barco1LlegoAlBorde) {
        if (reloj.getElapsedTime().asSeconds() >= 1) {
            int valorDado = dado.lanzarDado();
            for (int i = 0; i < valorDado; i++) {
                barco1.setPosition(barco1.getPosition().x + 10, barco1.getPosition().y);
            }
            if (barco1.getPosition().x >= 790) {
                barco1LlegoAlBorde = true;
                nombreBarcoGanador = "BARCO 1";
            }
            reloj.restart();
        }
    }

    if (event.type == Event::KeyPressed && event.key.code == Keyboard::D && !barco2LlegoAlBorde) {
        if (reloj.getElapsedTime().asSeconds() >= 1) {
            int valorDado = dado.lanzarDado();
            for (int i = 0; i < valorDado; i++) {
                barco2.setPosition(barco2.getPosition().x + 10, barco2.getPosition().y);
            }
            if (barco2.getPosition().x >= 790) {
                barco2LlegoAlBorde = true;
                nombreBarcoGanador = "BARCO 2";
            }
            reloj.restart();
        }
    }
}

bool Turnos::haGanadoAlgunBarco() {
    return barco1LlegoAlBorde || barco2LlegoAlBorde;
}

string Turnos::obtenerNombreGanador() {
    return nombreBarcoGanador;
}
