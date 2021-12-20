#include <iostream>
#include <vector>
#include "common/date.hpp"
#include "dto/usuario.hpp"
#include "dto/reserva.hpp"
#include "models/MaquinaModel.h"
#include "models/ReservaModel.h"
#include "models/UsuarioModel.h"

using namespace std;


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

	cute::suite s { };
	s.push_back(CUTE(testFecha));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {

    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
