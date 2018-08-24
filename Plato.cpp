#include "Plato.h"
#include <vector>
#include <iostream>
using namespace std;

	Plato::Plato(string pRes,int pPrecio){
		resena=pRes;
		precio=pPrecio;
		}

		void Plato::setSabor(int psabor){
			sabor=psabor;
		};
		int Plato::getSabor(){
			return sabor;
		};
		void Plato::setResena(string res){
			resena=res;
		};
		string Plato::getResena(){
			return resena;
		};
		void Plato::setIngrediente(Ingrediente i){
			//ing.push_back
		};
		Ingrediente* Plato::getIngrediente(int i){
			return ing[i];
		};
		vector<Ingrediente*> Plato::getIngredientes(){
			return ing;
		};


		void Plato::setCocinado(int pCocinado){
			cocinado=pCocinado;

		};
		int Plato::getCocinado(){
			return cocinado;
		};
		void Plato::setPrecio(int pPrecio){
			precio=pPrecio;
		};
		int Plato::getPrecio(){
			return precio;
		};
		void Plato::setValoracion(int pVal){
			valoracion=pVal;
		};
		int Plato::getValoracion(){
			return valoracion;

		};

		