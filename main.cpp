
#include <string>
#include <typeinfo>

#include <string>
using std::string;

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <vector>

using namespace std;
#include "Ingrediente.h"
#include "Plato.h"

void ingresarIgrediente(vector<Ingrediente*>&);
//void llenarVector(vector<Persona*>& pVector,int cantidadPersonas){
void ingresarPlato(vector<Plato*>&,vector<Ingrediente*>&);
void registrar();
void verRegistro();

int main(){
	vector<Ingrediente*>ing;
	vector<Plato*>menu;

	int opcion=0;
	do{
		cout<<"1)Ingresar Ingrediente"<<endl
		<<"2)Ingresar Plato"<<endl
		<<"3)registrar_Compra"<<endl
		<<"4)Registro de Compras"<<endl
		<<"5)Salir"<<endl
		<<"Que Desea hacer?: ";
		cin >> opcion;

		switch(opcion){
			case 1:
				ingresarIgrediente(ing);
				//cout<<ing[0]->getNombre()<<endl;
				break;
			case 2:
					if(ing.size()<3){
						cout<<"Deben de haber almenos 3 Ingredientes para crear un Plato...";
					}else{
						ingresarPlato(menu,ing);
					}
				break;

			case 3:
					if(menu.size()==0){
						cout<<"Debe haber por lo menos un Plato...";
					}else{
						registrar();
					}
				break;

			case 4:
				break;
		}
	}while(opcion!=5);
	cout<<"Hola"<<endl;

	return 0;
};

void ingresarIgrediente(vector<Ingrediente*>& vect){
	string nombre,tipo="";
	int cant,duracion;
	cout<<"Ingrese el Nombre del Ingrediente: ";
	cin>> nombre;
	cout<<"Ingrese la Cantidad de este Ingrediente: ";
	cin >>cant;
	cout<<"Ingrese la Duracion del Ingrediente: ";
	cin >> duracion;

	do{
		cout<<"Ingrese el tipo de Ingrediente [lacteo/vegetal/fruta/otros]: ";
		cin >>tipo;
//vegetales, frutas, otros, l
		cout<<(tipo.compare("lacteo")==0)<<endl;
	}while(! ((tipo.compare("lacteo")==0 ) ||  (tipo.compare("vegetal")==0 ) || (tipo.compare("fruta")==0 ) || (tipo.compare("otros")==0 )));
   	vect.push_back(new Ingrediente(cant,duracion,nombre,tipo));
}

void ingrearPlato(vector<Plato*>& platos,vector<Ingrediente*>& ingredientes){
		Ingrediente t;
		string resena;
		int precio=0,cont=0;
		vector<Ingrediente*> ing;

		cout<<"Ingrese una reseña del plato: ";
		cin >>resena;
		do{
		cout<<"Ingrese el precio del Plato";
		cin >>precio;
		}while(precio<1);
		platos.push_back(new Plato(resena,precio));
		int i=platos.size()-1;
		do{
			for(int j=0;j<ingredientes.size();j++){
				cout<<j<<") "<<ingredientes[j]->getNombre()<<endl;
			}
			cout<<j<<")Salir"
		}while(opcion)







}