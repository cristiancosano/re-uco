#include "../dto/reserva.hpp"
#include "./Model.h"

#ifndef MODELS_RESERVAMODEL_H_
#define MODELS_RESERVAMODEL_H_

class ReservaModel: protected Model<Reserva> {
	private:
		ReservaModel(): Model("reservas.txt"){}
		static ReservaModel * instance;
	public:
		static ReservaModel * getInstance();
		void create(Reserva * reserva);
		int getByUser(string user);
		vector <Reserva> getByDate(string date);
		
};

#endif /* MODELS_RESERVAMODEL_H_ */
