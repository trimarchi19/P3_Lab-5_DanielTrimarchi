#ifndef PLATO_H
#define PLATO_H

#include <string>
#include "Ingrediente.h"
#include <vector>
using namespace std;
class Plato{

	private:
		string resena;
		int sabor=0,cocinado=0,precio,valoracion=5;
		vector<Ingrediente*> ing;

	public:
		Plato();
		Plato(string,int);
		void setSabor(int);
		int getSabor();

		void setCocinado(int);
		int getCocinado();
		void setPrecio(int);
		int getPrecio();
		void setValoracion(int);
		int getValoracion();

		void setResena(string);
		string getResena();
		void setIngrediente(Ingrediente);
		Ingrediente* getIngrediente(int);
		vector<Ingrediente*> getIngredientes();


};
#endif