#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <iostream>
#include <vector>


using namespace std;

class Usuario {

private:

	string nombre;
	string mail;
	string password;
	string institucion;
	string rol;
	int limiteCPU;
	int limiteReserva;
	int limiteTiempo;

public:
	Usuario(){
		this->nombre = "";
		this->mail = "";
		this->password = "";
		this->institucion = "";
		this->rol = "";
		this->limiteCPU = 0;
		this->limiteReserva = 0;
		this->limiteTiempo = 0;
	}

	Usuario(string nombre, string mail, string password, string institucion,
			string rol, int limiteCPU, int limiteReserva, int limiteTiempo) {

		this->nombre = nombre;
		this->mail = mail;
		this->password = password;
		this->institucion = institucion;
		this->rol = rol;
		this->limiteCPU = limiteCPU;
		this->limiteReserva = limiteReserva;
		this->limiteTiempo = limiteTiempo;
	}

	Usuario(string mail, string password) {
		this->nombre = "";
		this->mail = mail;
		this->password = password;
		this->institucion = "";
		this->rol = "";
		this->limiteCPU = 0;
		this->limiteReserva = 0;
		this->limiteTiempo = 0;
	}

	inline void setNombre(string nombre) {this->nombre = nombre;}
	inline string getNombre() {return this->nombre;}
	inline void setMail(string mail) {this->mail = mail;}
	inline string getMail() {return this->mail;}
	inline void setPassword(string password) {this->password = password;}
	inline string getPassword() {return this->password;}
	inline void setInstitucion(string institucion) {this->institucion = institucion;}
	inline string getInstitucion() {return this->institucion;}
	inline void setRol(string rol) {this->rol = rol;}
	inline string getRol() {return this->rol;}
	inline void setLimiteCPU(int limiteCPU) {this->limiteCPU = limiteCPU;}
	inline int getLimiteCPU() {return this->limiteCPU;}
	inline void setLimiteReserva(int limiteReserva) {this->limiteReserva = limiteReserva;}
	inline int getLimiteReserva() {return this->limiteReserva;}
	inline void setLimiteTiempo(int limiteTiempo) {this->limiteTiempo = limiteTiempo;}
	inline int getLimiteTiempo() {return this->limiteTiempo;}
    inline bool isEmpty(){
    	return this->limiteCPU==0
    			&& this->limiteReserva==0
				&& this->limiteTiempo == 0
				&& this->nombre.length()==0
				&& this->mail.length()==0
				&& this->password.length()==0
				&& this->institucion.length()==0
				&& this->rol.length()==0;
    }


	bool obtenerRol();

	friend ostream& operator << (ostream &out, const Usuario &u);
	friend istream& operator >> (istream &in, Usuario &u);

};
#endif 

