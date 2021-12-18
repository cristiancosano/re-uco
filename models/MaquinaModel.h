#include "../dto/maquina.hpp"
#include "./Model.h"

#ifndef MODELS_MAQUINAMODEL_H_
#define MODELS_MAQUINAMODEL_H_

class MaquinaModel: protected Model<Maquina> {
	private:
		MaquinaModel(): Model("maquinas.txt"){}
		static MaquinaModel * instance;
	public:
		static MaquinaModel * getInstance();
		Maquina * getById(int id);
		void create(Maquina * maquina);
};

#endif /* MODELS_MAQUINAMODEL_H_ */
