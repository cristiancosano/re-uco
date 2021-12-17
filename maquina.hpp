#ifndef MAQUINA_HPP
#define MAQUINA_HPP

#include <string>

using namespace std;

class Maquina{

    private:
        
    int id;    
    int numeroCPU;
    int ram;
    string sistemaoperativo;

    public:
        
        inline void setId(int id){this->id = id;}
        inline int getId(){return this->id;}
        inline void setnumeroCPU(int numeroCPU){this->numeroCPU = numeroCPU;}
        inline int getnumeroCPU(){return this->numeroCPU;}
        inline void setRam(int ram){this->ram = ram;}
        inline int getRam(){return this->ram;}
        inline void setfechaInicio(string sistemaoperativo){this->sistemaoperativo = sistemaoperativo;}
        inline string getSistemaoperativo(){return this->sistemaoperativo;}
    };

#endif 
