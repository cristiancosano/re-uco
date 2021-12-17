#ifndef RESERVA_HPP
#define RESERVA_HPP

#include <string>

using namespace std;

class Reserva{

    private:
        
    int numeroCPU;
    string fechainicio;
    string fechafin;
    int idMaquina;
    string motivo;

    public:
        
    Reserva(int numeroCPU, string fechainicio, string fechafin, int idMaquina, string motivo){

        this->numeroCPU = numeroCPU;
        this->fechainicio = fechainicio;
        this->fechafin = fechafin;
        this->idMaquina = idMaquina;
        this->motivo = motivo;
    }

    inline void setnumeroCPU(int numeroCPU){this->numeroCPU = numeroCPU;}
    inline int getnumeroCPU(){return this->numeroCPU;}
    inline void setfechaInicio(string fechainicio){this->fechainicio = fechainicio;}
    inline string getfechaInicio(){return this->fechainicio;}
    inline void setfechaFin(string fechafin){this->fechafin = fechafin;}
    inline string getfechaFin(){return this->fechafin;}
    inline void setidMaquina(int idMaquina){this->idMaquina = idMaquina;}
    inline int getidMaquina(){return this->idMaquina;}
    inline void setMotivo(string motivo){this->motivo = motivo;}
    inline string getMotivo(){return this->motivo;}

    bool realizarReserva();
    bool eliminarReserva();

};

#endif 
