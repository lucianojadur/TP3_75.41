//
// Created by jose on 22/2/21.
//

#include "aire.h"
Aire :: Aire(string nombre,int escudo,int vida) : Personaje(nombre,escudo,vida){

}
Aire :: Aire(string nombre,int escudo,int vida,int energia, int fila , int columna,int condicion) : Personaje(nombre,escudo,vida,energia,fila,columna,condicion){

}


string Aire ::getElemento() {
    return "aire";
}
void Aire:: alimentarse() {
    vista.imprimirLinea("\nLos personajes de aire no se alimentan.\n");
}

bool Aire ::energiaAtaque() {

    return energia >= 8;
}

bool Aire ::energiaDefensa() {
    bool tieneEnergia = energia >= 15;
    if(tieneEnergia ){
        restarEnergia(15);
    }
    return tieneEnergia;
}

void Aire ::modificarPorTurno() {
    sumarEnergia(5);
}
int Aire :: danoAtaque(Personaje *personajeAtacar) {

    if(personajeAtacar -> getElemento() == "tierra")
        return 20;
    else if(personajeAtacar -> getElemento() == "fuego")
        return  10;
    else
        return 15;

}

void Aire ::atacar(Personaje** personajeAtacado) {

    restarEnergia(8);
    for(int i = 0; i < MAXRIVALES ; i++){
        if(personajeAtacado[i]->tieneVida()){
            int dano = danoAtaque(personajeAtacado[i]);
            quitarVidaPersonaje(personajeAtacado[i],dano);
        }
    }

}
int  Aire ::devolverCondicionEspecial() {
    return 0;
}


Aire ::~Aire() {

}