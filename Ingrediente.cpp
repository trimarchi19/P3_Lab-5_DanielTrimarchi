#include "Ingrediente.h"

#include <string>
using namespace std;

Ingrediente::Ingrediente(){

}
Ingrediente::Ingrediente(int pCant,int pDur,string pNom,string pTipo){
	cant=pCant;
	duracion=pDur;
	tipo=pTipo;
	nombre=pNom;
}
	int Ingrediente::getCant(){
		return cant;
	};
	void Ingrediente::setCant(int pCant){
		cant=pCant;
	};
	int Ingrediente::getDuracion(){
		return duracion;
	};
	void Ingrediente::setDuracion(int pDur){
		duracion=pDur;
	};
	string Ingrediente::getTipo(){
		return tipo;
	};
	void Ingrediente::setTipo(string pTipo){
		tipo=pTipo;
	};
		string Ingrediente::getNombre(){
			return nombre;
		};
	void Ingrediente::setNombre(string pNom){
		nombre=pNom;
	};