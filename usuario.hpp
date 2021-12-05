#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

using namespace std;

class usuario{

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

        usuario(string nombre, string mail, string password, string institucion, string rol, int limiteCPU, int limiteReserva, int limiteTiempo){

            this->nombre = nombre;
            this->mail = mail;
            this->nombre = nombre;
            this->institucion = institucion;
            this->rol = rol;
            this->limiteCPU = limiteCPU;
            this->limiteReserva = limiteReserva;
            this->limiteTiempo = limiteTiempo;
        }
        
        inline void setNombre(string nombre){this->nombre = nombre;}
        inline string getNombre(){return this->nombre;}
        inline void setMail(string mail){this->mail = mail;}
        inline string getMail(){return this->mail;}
        inline void setPassword(string password){this->password = password;}
        inline string getPassword(){return this->password;}
        inline void setInstitucion(string institucion){this->institucion = institucion;}
        inline string getInstitucion(){return this->institucion;}
        inline void setRol(string rol){this->rol = rol;}
        inline string getRol(){return this->rol;}
        inline void setLimiteCPU(int limiteCPU){this->limiteCPU = limiteCPU;}
        inline int getLimiteCPU(){return this->limiteCPU;}
        inline void setLimiteReserva(int limiteReserva){this->limiteReserva = limiteReserva;}
        inline int getLimiteReserva(){return this->limiteReserva;}
        inline void setLimiteTiempo(int limiteTiempo){this->limiteTiempo = limiteTiempo;}
        inline int getLimiteTiempo(){return this->limiteTiempo;}

        usuario buscarUsuario();
        void iniciarSesion();
        bool obtenerRol();

    };

#endif 