#include "MaquinaModel.h"

MaquinaModel * MaquinaModel::instance = nullptr;

MaquinaModel * MaquinaModel::getInstance(){
	if(MaquinaModel::instance == nullptr)
		MaquinaModel::instance = new MaquinaModel();
	return MaquinaModel::instance;
}

void MaquinaModel::create(Maquina * maquina){
	this->data.push_back(*maquina);
	this->storeData();
}

Maquina * MaquinaModel::getById(int id){
	for(auto &element : this->data)
		if(element.getId() == id) return &element;
	return nullptr;
}

vector <Maquina> MaquinaModel::getAll(){

	vector <Maquina> maquinas;

	for(auto &element : this->data)
		maquinas.push_back(element);

	return maquinas;
}