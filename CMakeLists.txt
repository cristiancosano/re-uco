CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(IS)
ENABLE_LANGUAGE(CXX)
set(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(main main.cpp dto/maquina.cpp dto/reserva.cpp dto/usuario.cpp models/MaquinaModel.cpp models/ReservaModel.cpp models/UsuarioModel.cpp)
