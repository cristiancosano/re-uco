#ifndef MAQUINA_HPP
#define MAQUINA_HPP

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Maquina{

    private:
        
    int id;    
    int numeroCPU;
    int ram;
    string sistemaOperativo;

    public:
    	Maquina(){
    		this->id = 0;
    		this->numeroCPU = 0;
    		this->ram = 0;
    		this->sistemaOperativo = "";
    	}
    	Maquina(int id, int numeroCPU, int ram, string sistemaOperativo){
    		this->id = id;
    		this->numeroCPU = numeroCPU;
    		this-> ram = ram;
    		this->sistemaOperativo = sistemaOperativo;
    	}

        
        inline void setId(int id){this->id = id;}
        inline int getId(){return this->id;}
        inline void setNumeroCPU(int numeroCPU){this->numeroCPU = numeroCPU;}
        inline int getNumeroCPU(){return this->numeroCPU;}
        inline void setRam(int ram){this->ram = ram;}
        inline int getRam(){return this->ram;}
        inline void setfechaInicio(string sistemaOperativo){this->sistemaOperativo = sistemaOperativo;}
        inline string getSistemaOperativo(){return this->sistemaOperativo;}
    	friend ostream& operator << (ostream &out, const Maquina &m);
    	friend istream& operator >> (istream &in, Maquina &m);
	};
#endif 
