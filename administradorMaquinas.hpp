#ifndef ADMINISTRADORMAQUINAS_HPP
#define ADMINISTRADORMAQUINAS_HPP

#include <string>

#include <usuario.hpp>

using namespace std;

class administradorMaquinas : public usuario{

    private:
        
    public:
        
        bool añadirMaquina();
        bool eliminarMaquina();
        bool eliminarMaquina();
    };

#endif 