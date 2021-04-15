#include "tierra.h"
Tierra :: Tierra(string nombre,int escudo,int vida) : Personaje(nombre,escudo,vida){
    escudoInicial = escudo;
}
Tierra :: Tierra(string nombre,int escudo,int vida,int energia, int fila , int columna,int condicion) : Personaje(nombre,escudo,vida,energia,fila,columna,condicion){
escudoInicial = condicion;
}

string Tierra ::getElemento() {
   return "tierra";
}

void Tierra::alimentarse() {

    if(verificarEnergia()){
        energia = energia + 8;
        imprimirAlimentos();
    }else
        vista.noSeAlimento();
}

bool Tierra::verificarEnergia() {

    return ( energia + 8 <= EMAX);
}

void Tierra :: imprimirAlimentos(){

  vista.alimentado(getElemento(),"hierbas",8);

}
bool Tierra :: energiaAtaque() {

    return energia >= 6;
}

bool Tierra ::energiaDefensa() {

    bool tieneEnergia = energia >= 5;
    if(tieneEnergia ){
        restarEnergia(5);
    }
    return tieneEnergia;
}

int Tierra ::danoAtaque(int valorAtaque, Personaje *personajeAtacar) {

    if(personajeAtacar -> getElemento() == "aire")
        valorAtaque = 10;
    else if(personajeAtacar -> getElemento() == "agua")
        valorAtaque = valorAtaque + 20;
    return valorAtaque;
}


int Tierra ::danoPorRango(int filaAtacar, int columnaAtacar, int filaAtacado, int columnaAtacado) {

    int diferenciaFilas = filaAtacar-filaAtacado;
    int diferenciaColumnas = columnaAtacar-columnaAtacado;

    if(diferenciaFilas <= 2 && diferenciaFilas >= -2 )
        return condicionRangoDos(diferenciaColumnas);
    else if(diferenciaFilas <= 4 && diferenciaFilas >= -4)
        return condicionRangoCuatro(diferenciaColumnas);
    else
        return 10;
}

int Tierra ::condicionRangoDos(int diferenciaCol) {

    if(diferenciaCol <= 2 && diferenciaCol >= -2)
        return 30;
    else if(diferenciaCol <= 4 && diferenciaCol >= -4)
        return 20;
    else
        return 10;
}

int Tierra ::condicionRangoCuatro(int diferenciaCol) {
    if(diferenciaCol <= 4 && diferenciaCol >= -4)
        return 20;
    else
        return 10;
}

void Tierra :: atacar(Personaje** personajeAtacado ){
   restarEnergia(6);
    for(int i = 0; i < MAXRIVALES ; i++){
        if(personajeAtacado[i]->tieneVida()){
            int danoRango = danoPorRango(fila,columna,personajeAtacado[i]->getFila(),personajeAtacado[i]->getColumna());
            int dano = danoAtaque(danoRango,personajeAtacado[i]);
            quitarVidaPersonaje(personajeAtacado[i],dano);
        }

    }
}
int Tierra::devolverCondicionEspecial() {
    return escudoInicial;
}

void Tierra ::modificarPorTurno() {
    if(escudoInicial != escudo)
        escudo = escudoInicial;
}

Tierra ::~Tierra() {

}