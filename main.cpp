#include <iostream>
#include <vector>
#include "dto/usuario.hpp"
#include "dto/reserva.hpp"
#include "models/MaquinaModel.h"
#include "models/ReservaModel.h"

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
	
	Usuario * user = new Usuario("Pedro", "i82gapop@uco.es", "Abc12", "UCO", "Investigador", 2, 3, 2);

	ReservaModel * rm = ReservaModel::getInstance();

	if (rm->getByUser(user->getMail()) >= user->getLimiteReserva()){
		
		cout << "Su cupo de reservas ha sido superado, debe hacer hueco antes de hacer otra reserva." << endl;
		return;
	}	

	cout << "Introduce el dia para el que quieres la reserva: " << endl;
	string day;
	cin >> day;

	cout << "Introduce el numero del mes para el que quieres la reserva: " << endl;
	string month;
	cin >> month;
	
	cout << "Introduce el numero del año (en cuatro digitos) para el que quieres la reserva: " << endl;
	string year;
	cin >> year;

	cout << "Introduce el numero de dias que quieres tener la maquina: " << endl;
	int duracion;
	cin >> duracion;

	MaquinaModel * md = MaquinaModel::getInstance();

	vector <Maquina> maquinas = md->getAll();

	for(auto &element : maquinas)

		cout << element << endl;

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

	/*Maquina * maquina = new Maquina(1, 2, 3, "Linux");
	MaquinaModel * md = MaquinaModel::getInstance();*/
	//cout << *md->getById(3);
	/*md->create(maquina);*/

	Usuario * user = NULL;

	bool isValidUser = false;

	while(!isValidUser){
		user = getUsuario();
		isValidUser = user->iniciarSesion();
		cout << endl << ((!isValidUser) ? "Datos incorrectos. Intentelo de nuevo" : "Usuario autenticado. Bienvenido") << endl << endl;
	}

	menu();
}
