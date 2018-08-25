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
	int Ingrediente::getUsados(){
		return usados;
	}
	void Ingrediente::setUsados(int pUs){
		usados=pUs;
	}
	int Ingrediente::getLlenado(){
		return llenado;
	}
	void Ingrediente::setLlenado(int pUs){
		llenado=pUs;
	}