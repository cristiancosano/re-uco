#ifndef RESERVA_HPP
#define RESERVA_HPP

#include <string>
#include <iostream>
#include <vector>


using namespace std;

class Reserva{

    private:
        
    int numeroCPU;
    string fechaInicio;
    string fechaFin;
    int idMaquina;
    string motivo;

    public:

    Reserva(){
    	this->numeroCPU = 0;
		this->fechaInicio = "";
		this->fechaFin = "";
		this->idMaquina = 0;
		this->motivo = "";
    }
        
    Reserva(int numeroCPU, string fechaInicio, string fechaFin, int idMaquina, string motivo){

        this->numeroCPU = numeroCPU;
        this->fechaInicio = fechaInicio;
        this->fechaFin = fechaFin;
        this->idMaquina = idMaquina;
        this->motivo = motivo;
    }

    inline void setnumeroCPU(int numeroCPU){this->numeroCPU = numeroCPU;}
    inline int getnumeroCPU(){return this->numeroCPU;}
    inline void setfechaInicio(string fechaInicio){this->fechaInicio = fechaInicio;}
    inline string getfechaInicio(){return this->fechaInicio;}
    inline void setfechaFin(string fechaFin){this->fechaFin = fechaFin;}
    inline string getfechaFin(){return this->fechaFin;}
    inline void setidMaquina(int idMaquina){this->idMaquina = idMaquina;}
    inline int getidMaquina(){return this->idMaquina;}
    inline void setMotivo(string motivo){this->motivo = motivo;}
    inline string getMotivo(){return this->motivo;}

    bool realizarReserva();
    bool eliminarReserva();

    friend ostream& operator << (ostream &out, const Reserva &r);
    friend istream& operator >> (istream &in, Reserva &r);
};

#endif 
