#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <vector>
#include "dto/usuario.hpp"
#include "dto/reserva.hpp"
#include "dto/maquina.hpp"

class Sistema
{

private:

vector <Usuario> usuarios;
vector <Reserva> reservas;
vector <Maquina> maquinas;


protected:

    Sistema(){

        
    }

    static Sistema* sistema;

public:

    Sistema(Sistema &other) = delete;
    void operator=(const Sistema &) = delete;
    static Sistema *getInstance();

    inline void setUsuarios(vector <Usuario> usuarios){this->usuarios = usuarios;}
    inline vector <Usuario> getUsuarios(){return this->usuarios;}
    inline void setReservas(vector <Reserva> reservas){this->reservas = reservas;}
    inline vector <Reserva> getReservas(){return this->reservas;}
    inline void setMaquinas(vector <Maquina> maquinas){this->maquinas = maquinas;}
    inline vector <Maquina> getMaquinas(){return this->maquinas;}

    void leerFichero();
    void escribirFichero();
    Reserva * getReservaByIdMaquina(int idMaquina);
    Usuario * getUsuarioByEmail(string email);



};


#endif















