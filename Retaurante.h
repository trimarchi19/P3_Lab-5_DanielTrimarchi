#ifndef RESTAURANTE_H
#define RESTAURANTE_H
#include <vector>
using std::vector;
#include "Ingrediente.h"
#include "Plato.h"

class Restaurante{
private:
		vector<Ingrediente*>ing;
	vector<Plato*>menu;

public:
	void setIngrediente(Ingrediente);
	Restaurante();


};
#endif