#ifndef ADMINISTRADORMAQUINAS_HPP
#define ADMINISTRADORMAQUINAS_HPP

#include <string>

#include <usuario.hpp>

using namespace std;

class administradorMaquinas : public Usuario{

    private:
        
    public:
        
        bool anadirMaquina();
        bool eliminarMaquina();
        bool eliminarMaquina();
    };

#endif 
