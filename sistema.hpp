#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <vector>
#include "usuario.hpp"
#include "reserva.hpp"
#include "maquina.hpp"

class Sistema
{

private:

vector <usuario> usuarios;
vector <reserva> reservas;
vector <maquina> maquinas;


protected:

    Sistema(){

        
    }

    static Sistema* sistema;

public:

    Sistema(Sistema &other) = delete;
    void operator=(const Sistema &) = delete;
    static Sistema *GetInstance();

    inline void setUsuarios(vector <usuario> usuarios){this->usuarios = usuarios;}
    inline vector <usuario> getUsuarios(){return this->usuarios;}
    inline void setReservas(vector <reserva> reservas){this->reservas = reservas;}
    inline vector <reserva> getReservas(){return this->reservas;}
    inline void setMaquinas(vector <maquina> maquinas){this->maquinas = maquinas;}
    inline vector <maquina> getMaquinas(){return this->maquinas;}

    void leerFichero();
    void escribirFichero();

};

Sistema *Sistema::GetInstance(){

    if(sistema==nullptr){

        sistema = new Sistema();
    }

    return sistema;
}


#endif















