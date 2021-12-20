
#include <iostream>
#include <vector>
#include "common/date.hpp"
#include "dto/usuario.hpp"
#include "dto/reserva.hpp"
#include "models/MaquinaModel.h"
#include "models/ReservaModel.h"
#include "models/UsuarioModel.h"
#include "cute/cute.h"
#include "cute/cute_runner.h"
#include "cute/xml_listener.h"
#include "cute/ide_listener.h"


using namespace std;

void testEliminarReserva(){

	Date fecha(2000, 6, 3);
	Date fecha2(2021, 4, 3);

	Reserva * reserva = new Reserva(1, 3, fecha.toString(), fecha2.toString(), 3, "Test", "antoniolrj4@gmail.com");


	ASSERT_EQUAL(reserva->eliminarReserva(), true);
}

void testMostrarReserva(){

	Date fecha(2000, 6, 3);
	Date fecha2(2021, 4, 3);
	Reserva * reserva = new Reserva(1, 3, fecha.toString(), fecha2.toString(), 3, "Test", "antoniolrj4@gmail.com");
	ASSERT_EQUAL(reserva->mostrarReserva(), true);

}

void testLogin(){
	UsuarioModel * um = UsuarioModel::getInstance();
	Usuario * user = um -> login("antoniolrj4", "secret");
	ASSERT_EQUAL(user->getMail(), "antoniolrj4");
	ASSERT_NOT_EQUAL_TO(user->getMail(), "antonio");
}

void testRealizarReserva(){
	Reserva * reserva = new Reserva(1, 3, fecha.toString(), fecha2.toString(), 3, "Test", "antoniolrj4@gmail.com");
	ASSERT_EQUAL(reserva->realizarReserva(), true);

}
void testFecha1() {

	Date fecha(2000, 6, 3);

	ASSERT_EQUAL(fecha.toString(), "2000-6-3");
}

void testFecha2() {

	Date fecha(2000, 6, 3);
	Date fecha2(2000, 6, 5);
	fecha+=(2);

	ASSERT_EQUAL(fecha.toString(), fecha2.toString());
}


bool runAllTests(int argc, char const *argv[]) {

	cute::suite s;
	s.push_back(CUTE(testFecha1));
	s.push_back(CUTE(testFecha2));
	s.push_back(CUTE(testLogin));
	s.push_back(CUTE(testEliminarReserva));
	s.push_back(CUTE(testRealizarReserva));
	s.push_back(CUTE(testMostrarReserva));


	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {

    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
