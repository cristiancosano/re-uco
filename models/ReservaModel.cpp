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


