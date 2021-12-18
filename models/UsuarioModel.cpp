#include "UsuarioModel.h"

UsuarioModel * UsuarioModel::instance = nullptr;

UsuarioModel * UsuarioModel::getInstance(){
	if(UsuarioModel::instance == nullptr)
		UsuarioModel::instance = new UsuarioModel();
	return UsuarioModel::instance;
}

void UsuarioModel::create(Usuario * usuario){
	this->data.push_back(*usuario);
	this->storeData();
}


