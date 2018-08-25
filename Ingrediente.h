#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <string>
using namespace std;
/*
r el nombre, el tipo, el cual solo puede ser lácteo, vegetales, frutas, otros, 
la cantidad de aporte al sabor del plato y una duración n, la cual hace que cada n compras se disminuya el 10% de la cantidad.
*/
class Ingrediente{
private:

	string tipo,nombre;
	int cant,duracion,usados=0,llenado=0;
public:
	int getUsados();
	void setUsados(int);

int getLlenado();
	void setLlenado(int);

	int getCant();
	void setCant(int);
	int getDuracion();
	void setDuracion(int);
	string getTipo();
	void setTipo(string);

		string getNombre();
	void setNombre(string);
	Ingrediente();
	Ingrediente(int,int,string,string);
	~Ingrediente();
};

#endif