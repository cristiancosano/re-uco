#include "../dto/usuario.hpp"
#include "./Model.h"

#ifndef MODELS_USUARIOMODEL_H_
#define MODELS_USUARIOMODEL_H_

class UsuarioModel: protected Model<Usuario> {
	private:
		UsuarioModel(): Model("usuarios.txt"){}
		static UsuarioModel * instance;
	public:
		static UsuarioModel * getInstance();
		Usuario * getByMail(string mail);
		void create(Usuario * usuario);
};

#endif /* MODELS_USUARIOMODEL_H_ */
