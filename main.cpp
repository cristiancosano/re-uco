#include <iostream>
#include "dto/usuario.hpp"
#include "dto/reserva.hpp"
#include "sistema.hpp"
#include "models/MaquinaModel.h"
using namespace std;

Usuario * getUsuario(){
	string mail, password;
	cout<<"Introduce tu mail: ";
	cin>>mail;

	cout<<"Introduce tu password: ";
	cin>>password;

	Usuario * user = new Usuario(mail, password);
	return user;
}

void realizarReserva(){
	//int numeroCPU, idMaquina;
	//string fechaInicio, fechaFin, motivo;
	//Reserva * reserva = new Reserva(numeroCPU, fechaInicio, fechaFin, idMaquina, motivo);

}

void menu(){
	int opcion = 0;
	while(opcion != 3){
		cout << "=== MENU PRINCIPAL ===" << endl;
		cout << "1. Realizar reserva" << endl;
		cout << "2. Eliminar reserva" << endl;
		cout << "3. Salir" << endl << endl;

		cout << "Elija una opción: ";
		cin >> opcion;

		switch(opcion){
			case 1:
				cout << endl;
				realizarReserva();
				cout << endl;
				break;
			case 2:
				cout << endl;
				cout<<"eliminar reserva" << endl;
				cout << endl;
				break;
			case 3:
				cout << endl;
				cout << "Hasta pronto!" << endl;
				cout << endl;
				break;
			default:
				cout << endl;
				cout << "La opcion elegida no es valida" << endl;
				cout << endl;

		}
	}
}

int main(int argc, const char * argv[]) {
	cout<<"====== RE-UCO ======"<<endl<<endl;

	Maquina * maquina = new Maquina(1, 2, 3, "Linux");
	MaquinaModel * md = MaquinaModel::getInstance();
	//cout << *md->getById(3);
	md->create(maquina);

	//Sistema * sistema = Sistema::getInstance();

	Usuario * user = NULL;

	bool isValidUser = false;

	while(!isValidUser){
		user = getUsuario();
		isValidUser = user->iniciarSesion();
		cout << endl << ((!isValidUser) ? "Datos incorrectos. Intentelo de nuevo" : "Usuario autenticado. Bienvenido") << endl << endl;
	}

	menu();
}
