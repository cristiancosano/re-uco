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
		void remove(int id);
		int getByUser(string user);
		vector <Reserva> getAll();
		vector <Reserva> getByDate(string date);
		vector <Reserva> getReservasByUser(string user);
};

#endif /* MODELS_RESERVAMODEL_H_ */
