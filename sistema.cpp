#include "sistema.hpp"

void leerFichero(){

}

void escribirFichero(){

}

Reserva * Sistema::getReservaByIdMaquina(int idMaquina){

	return nullptr;
}

Sistema * Sistema::sistema = nullptr;

Sistema *Sistema::getInstance(){

    if(sistema==nullptr){

        sistema = new Sistema();
    }

    return sistema;
}

