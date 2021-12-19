#include "ReservaModel.h"

ReservaModel * ReservaModel::instance = nullptr;

ReservaModel * ReservaModel::getInstance(){
	if(ReservaModel::instance == nullptr)
		ReservaModel::instance = new ReservaModel();
	return ReservaModel::instance;
}

void ReservaModel::create(Reserva * reserva){
	this->data.push_back(*reserva);
	this->storeData();
}

int ReservaModel::getByUser(string user){

	int contador = 0;

	for(auto &element : this->data)
		if(element.getUsuario() == user) contador++;
	return contador;
}

int ReservaModel::getBy(string user){

	int contador = 0;

	for(auto &element : this->data)
		if(element.getUsuario() == user) contador++;
	return contador;
}
