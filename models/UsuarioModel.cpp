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

Usuario * UsuarioModel::login(string mail, string password){
	for(auto &element : data){
		if(element.getMail().compare(mail) == 0){
			if(element.getPassword().compare(password) == 0) return &element;
			else return nullptr;
		}
	}
	return nullptr;
}

