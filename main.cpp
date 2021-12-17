#include <iostream>
#include "usuario.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
	cout<<"====== RE-UCO ======"<<endl<<endl;

	string mail, password;

	cout<<"Introduce tu mail: ";
	cin>>mail;

	cout<<"Introduce tu password: ";
	cin>>password;

	bool isValidUser = false;

	while(!isValidUser){
		Usuario * user = new Usuario(mail, password);
		isValidUser = user->iniciarSesion();
		cout << ((!isValidUser) ? "Datos incorrectos. Intentelo de nuevo" : "Usuario autenticado. Bienvenido") << endl;
	}

	int opcion = 0;

	do{
		cout << "=== MENU PRINCIPAL ===" << endl;
		cout << "1. Realizar reserva" << endl;
		cout << "2. Eliminar reserva" << endl << endl;
		cout << "3. Salir" << endl << endl;

		cout << "Elija una opción: ";
	} while (opcion != 3);

	cout << "Hasta pronto!" << endl;

}
