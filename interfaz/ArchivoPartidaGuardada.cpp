//
// Created by jose on 26/2/21.
//

#include "ArchivoPartidaGuardada.h"

void ArchivoPartidaGuardada::cargarPartida(Juego *juego, Matriz* &tablero) {
    ifstream archivo;
    archivo.open("partida.csv");
    string linea, aux, elemento, nombre;
    int contador = 0;
    int vida, escudo, energia, fila, columna, condicionEspecial;
    archivo >> aux;
    cout << aux << endl;
    juego->setPersonajeGuardo(stoi(aux));
    getline(archivo, aux, '\n');
    while (!archivo.eof()) {
        if (getline(archivo, aux, ',')) {
            elemento = aux;
            getline(archivo, aux, ',');
            nombre = aux;
            getline(archivo, aux, ',');
            escudo = std::stoi(aux);
            getline(archivo, aux, ',');
            vida = std::stoi(aux);
            getline(archivo, aux, ',');
            energia = std::stoi(aux);
            getline(archivo, aux, ',');
            fila = std::stoi(aux);
            getline(archivo, aux, ',');
            columna = std::stoi(aux);
            getline(archivo, aux, '\n');
            condicionEspecial = std::stoi(aux);
            Personaje* auxPersonaje = crearPersonaje(elemento,nombre,escudo,vida,energia,fila,columna,condicionEspecial);
            tablero->setHayPersonaje(fila, columna, true);
            juego->leerPersonajesArchivo(auxPersonaje,contador);
            contador++;
        }
    }
    archivo.close();
}

Personaje* ArchivoPartidaGuardada ::crearPersonaje(
    string elemento,
    string nombre,
    int escudo,
    int vida,
    int energia,
    int fila,
    int columna,
    int condicionEspecial) 
{
        Personaje* p;
        if(elemento == "agua")
            p = new Agua(nombre, escudo, vida,energia,fila,columna,condicionEspecial);
        else if(elemento == "tierra")
            p = new Tierra(nombre, escudo, vida,energia,fila,columna,condicionEspecial);
        else if(elemento == "aire")
            p = new Aire(nombre, escudo, vida,energia,fila,columna,condicionEspecial);
        else
            p = new Fuego(nombre, escudo, vida,energia,fila,columna,condicionEspecial);

        return p;

}