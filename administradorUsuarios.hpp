#ifndef ADMINISTRADORUSUARIOS_HPP
#define ADMINISTRADORUSUARIOS_HPP

#include <string>

#include <usuario.hpp>

using namespace std;

class administradorUsuarios : public usuario{

    private:
        
    public:
        
        bool eliminarUsuario();
        bool modificarUsuario();
        bool añadirUsuario();
    };

#endif 