#include "ReservaModel.h"
#include "common/date.hpp"

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

vector <Reserva> ReservaModel::getByDate(string date){

	vector <Reserva> reservas;

	for(auto &element : this->data)
		if(element.getfechaInicio() == date) reservas.push_back(element);
		
	return reservas;
}

vector <Reserva> ReservaModel::getReservasByUser(string user){

	vector <Reserva> reservas;

	for(auto &element : this->data)
		if(element.getUsuario == user) reservas.push_back(element);

	return reservas;
}

vector <Reserva> ReservaModel::getAll(){

	vector <Reserva> reservas;

	for(auto &element : this->data)
		reservas.push_back(element);

	return reservas;
}

void ReservaModel::remove(int id){

	for(int i=0; i < this->data.size(); i++){
		if(id == data[i].getId()){
			data.erase(&data[i]);
		}
	}

	this->storeData();
}
