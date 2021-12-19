#include "reserva.hpp"

ostream& operator << (ostream &out, const Reserva &r){
	const string delimiter = ", ";
	out << "(" << r.numeroCPU << delimiter << r.fechaInicio << delimiter << r.fechaFin << delimiter << r.idMaquina << delimiter << r.motivo << delimiter << r.usuario << ")";
	return out;
}

istream& operator >> (istream &in, Reserva &r){
	const string delimiter = ", ";
	string element;
	getline(in, element);
	if(element.length() != 0){

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

		r.numeroCPU = stoi(data[0]);
		r.fechaInicio = data[1];
		r.fechaFin = data[2];
		r.idMaquina = stoi(data[3]);
		r.motivo = data[4];
		r.usuario = data[5];
	}
	return in;
}

