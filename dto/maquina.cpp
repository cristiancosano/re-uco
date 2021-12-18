#include "maquina.hpp"

ostream& operator << (ostream &out, const Maquina &m){
	const string delimiter = ", ";
	out << "(" << m.id << delimiter << m.numeroCPU << delimiter << m.ram << delimiter << m.sistemaOperativo << ")";
	return out;
}

istream& operator >> (istream &in, Maquina &m){
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


	m.id = stoi(data[0]);
	m.numeroCPU = stoi(data[1]);
	m.ram = stoi(data[2]);
	m.sistemaOperativo = data[3];

	return in;
}
