#include "../dto/maquina.hpp"
#include "./Model.h"

#include <vector>

#ifndef MODELS_MAQUINAMODEL_H_
#define MODELS_MAQUINAMODEL_H_

class MaquinaModel: protected Model<Maquina> {
	private:
		MaquinaModel(): Model("maquinas.txt"){}
		static MaquinaModel * instance;
	public:
		static MaquinaModel * getInstance();
		Maquina * getById(int id);
		vector <Maquina> getAll();
		void create(Maquina * maquina);
};

#endif /* MODELS_MAQUINAMODEL_H_ */
