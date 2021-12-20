#include <iostream>
#include <vector>
#include "common/date.hpp"
#include "dto/usuario.hpp"
#include "dto/reserva.hpp"
#include "models/MaquinaModel.h"
#include "models/ReservaModel.h"
#include "models/UsuarioModel.h"

using namespace std;

Usuario * getUsuario(){
	string mail, password;
	cout<<"Introduce tu mail: ";
	cin>>mail;

	cout<<"Introduce tu password: ";
	cin>>password;

	UsuarioModel * um = UsuarioModel::getInstance();
	Usuario * user = um->login(mail, password);
	return user;
}

void realizarReserva(Usuario * user){
	
	//Usuario * user = new Usuario("Pedro", "i82gapop@uco.es", "Abc12", "UCO", "Investigador", 2, 3, 2);

	ReservaModel * rm = ReservaModel::getInstance();

	if (rm->getByUser(user->getMail()) >= user->getLimiteReserva()){
		
		cout << "Su cupo de reservas ha sido superado, debe hacer hueco antes de hacer otra reserva." << endl;
		return;
	}	

	cout << "Introduce el dia para el que quieres la reserva: " << endl;
	int day;
	cin >> day;

	cout << "Introduce el numero del mes para el que quieres la reserva: " << endl;
	int month;
	cin >> month;
	
	cout << "Introduce el numero del año (en cuatro digitos) para el que quieres la reserva: " << endl;
	int year;
	cin >> year;

	Date fecha(year, month, day);
	Date fecha2 = fecha;

	cout << "Introduce el numero de dias que quieres tener la maquina: " << endl;
	int duracion;
	cin >> duracion;

	fecha2+=(duracion);

	if(duracion > user->getLimiteTiempo()){

		cout << "Su tiempo de reserva elegido es mayor del limite establecido para su usuario." << endl;
		return;
	}

	cout << "Introduce el numero de CPU's que quiere usar: " << endl;
	int cpu;
	cin >> cpu;

	if(cpu > user->getLimiteCPU()){

		cout << "Su numero de cpu elegido es mayor del limite establecido para su usuario." << endl;
		return;
	}

	vector <Reserva> reservas = rm->getByDate(fecha.toString());

	MaquinaModel * md = MaquinaModel::getInstance();

	vector <Maquina> maquinas = md->getAll();

	for(auto &element : reservas){

		for(auto &element2 : maquinas){

			if(element.getId() == element2.getId()){

				element2.setNumeroCPU(element2.getNumeroCPU()-element.getnumeroCPU());
			}
		}
	}

	vector <Maquina> maquinasdisponibles;
	int contador = 0;

	cout << "Las maquinas disponibles para reservar en ese dia son las siguientes: " << endl;

	for(auto &element : maquinas){

		if(element.getNumeroCPU() >= cpu){
			
			maquinasdisponibles.push_back(element);
			cout << contador+1 << ". " << element << endl;
			contador++;
		}	
	}

	cout << "\nElija el numero de la maquina que quiere reservar: " << endl;
	int maquina;
	cin >> maquina;

	if(maquina > maquinasdisponibles.size()){

		cout << "La maquina que ha elegido no existe." << endl;
		return;
	}

	cout << "Por ultimo introduzca el motivo de la reserva: " << endl;
	string motivo;

	getchar();
	getline(cin, motivo);

	/*reservas = rm->getAll();
	int id = reservas.back().getId();*/

	Reserva * reserva = new Reserva(1, cpu, fecha.toString(), fecha2.toString(), maquinasdisponibles[maquina-1].getId(), motivo, user->getMail());
	rm->create(reserva);

	cout << "La reserva ha sido creada con exito." << endl;
}

void mostrarReservas(Usuario * user){

	MaquinaModel * mm = MaquinaModel::getInstance();
	ReservaModel * rm = ReservaModel::getInstance();
	vector <Reserva> reservas;

	if(user->getRol() == "administradorMaquinas"){

		reservas = rm->getAll();

		for(int i = 0; i < reservas.size(); i++){
			cout << "Reserva del usuario: " + reservas[i].getUsuario() + ", Fecha inicio: " + reservas[i].getfechaInicio() + " , Fecha fin : " + reservas[i].getfechaFin()  << endl;
		}

	}
	else{

		reservas = rm->getReservasByUser(user->getNombre());
		cout << "Introduce el id de la reserva que desea eliminar: ";

		for(int i = 0; i < reservas.size(); i++){
			cout << "Reserva del usuario: " + reservas[i].getUsuario() + ", Fecha inicio: " + reservas[i].getfechaInicio() + " , Fecha fin : " + reservas[i].getfechaFin()  << endl;
		}

	}
}
void eliminarReserva(Usuario * user){

	ReservaModel * rm = ReservaModel::getInstance();
	vector <Reserva> reservas;


	if(user->getRol() == "administradorMaquinas"){

		int idReserva;
		reservas = rm->getAll();
		cout << "Introduce el id de la reserva que desea eliminar: ";

		for(int i = 0; i < reservas.size(); i++){
			cout << "Reserva del usuario: " + reservas[i].getUsuario() + ", Fecha inicio: " + reservas[i].getfechaInicio() + " , Fecha fin : " + reservas[i].getfechaFin()  << endl;
		}

		cin >> idReserva;

		rm->remove(idReserva);

	}else{

		int idReserva;
		reservas = rm->getReservasByUser(user->getNombre());
		cout << "Introduce el id de la reserva que desea eliminar: ";

		for(int i = 0; i < reservas.size(); i++){
			cout << "Reserva del usuario: " + reservas[i].getUsuario() + ", Fecha inicio: " + reservas[i].getfechaInicio() + " , Fecha fin : " + reservas[i].getfechaFin()  << endl;
		}

		cin >> idReserva;

		rm->remove(idReserva);
	}

}

void menu(Usuario * user){
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
				realizarReserva(user);
				cout << endl;
				break;
			case 2:
				cout << endl;
				eliminarReserva(user);
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

	Usuario * user = nullptr;

	while(user == nullptr){
		user = getUsuario();
		cout << endl << ((user == nullptr) ? "Datos incorrectos. Intentelo de nuevo" :"Bienvenido " + user->getNombre() + " nos alegra tenerte aqui de nuevo!") << endl << endl;
	}

	menu(user);
}
