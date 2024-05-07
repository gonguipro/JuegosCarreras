#pragma once

#include "barcos.h"
#include "dado.h"

using namespace std;
using namespace sf;

class Turnos {
private:
    Barco& barco1;
    Barco& barco2;
    Dado& dado;
    Clock reloj;
    bool barco1LlegoAlBorde;
    bool barco2LlegoAlBorde;
    string nombreBarcoGanador;
    RenderWindow& window;

public:
    Turnos(Barco&, Barco&, Dado&, RenderWindow&);
    void verificarTurnos(Event);
    bool haGanadoAlgunBarco();
    string obtenerNombreGanador();
};


