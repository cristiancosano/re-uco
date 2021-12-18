#include "usuario.hpp"
#include "reserva.hpp"


bool Usuario::iniciarSesion(){
	return true;
}


ostream& operator << (ostream &out, const Usuario &u){
	const string delimiter = ", ";
	out << "(" << u.nombre << delimiter << u.mail << delimiter << u.password << delimiter << u.institucion << delimiter << u.rol << delimiter << u.limiteCPU << delimiter << u.limiteReserva << delimiter << u.limiteTiempo << ")";
	return out;
}

istream& operator >> (istream &in, Usuario &u){
	const string delimiter = ", ";
	string element;
	getline(in, element);
	element = element.substr(1, element.length()-2);
	size_t pos = 0;
	std::vector<string> data;

	while (element.length() > 0) {
		pos = element.find(delimiter);
	    data.push_back(element.substr(0, pos));
	    if(pos != element.npos)
	    	element.erase(0, pos + delimiter.length());
	    else element.erase(0);
	}

	u.nombre = data[0];
	u.mail = data[1];
	u.password = data[2];
	u.institucion = data[3];
	u.rol = data[4];
	u.limiteCPU = stoi(data[5]);
	u.limiteReserva = stoi(data[6]);
	u.limiteTiempo = stoi(data[7]);

	return in;
}

