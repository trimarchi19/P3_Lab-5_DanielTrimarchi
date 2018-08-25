
#include <string>
#include <typeinfo>

#include <string>
using std::string;

#include <iostream>

#include <sstream>
using std::cout;
using std::cin;
using std::endl;

#include <vector>

using namespace std;
#include "Ingrediente.h"
#include "Plato.h"

void ingresarIgrediente(vector<Ingrediente*>&);
//void llenarVector(vector<Persona*>& pVector,int cantidadPersonas){
void ingresarPlato(vector<Plato*> &,vector<Ingrediente*> &);
void registrar(vector<Plato*> &,int&,vector<string>&);
void verRegistro(vector<string>&);
void intinerario(Plato*);

int main(){
	vector<Ingrediente*>ing;
	vector<Plato*>menu;
	vector<string> clientes;
	int dinero=0;
	int opcion=0;
	do{
		cout<<"---------------------------------"<<endl<<endl;
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
					if(ing.size()<2){
						cout<<"Deben de haber almenos 2 Ingredientes para crear un Plato..."<<endl;
					}else{
						ingresarPlato(menu,ing);
					}
				break;

			case 3:
					if(menu.size()==0){
						cout<<"Debe haber por lo menos un Plato..."<<endl;
					}else{
						registrar(menu,dinero,clientes);
					}
				break;

			case 4:
				verRegistro(clientes);
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

void ingresarPlato(vector<Plato*>& platos,vector<Ingrediente*>& ingredientes){
		//Ingrediente t;
	cout<<"--------------------"<<endl<<endl;
		string resena,nombre;
		int precio=0,cont=0,opcion,pos;
		vector<Ingrediente*> ing;
		bool listo=false;
		cout<<"Ingrese el Nombre del Plato: ";
		cin >>nombre;
		cout<<"Ingrese una reseña del plato: ";
		cin >>resena;
		do{
		cout<<"Ingrese el precio del Plato: ";
		cin >>precio;
		}while(precio<1);
		platos.push_back(new Plato(resena,precio,nombre));
		int i=platos.size()-1;
		do{
			cout<<"--------------------------------"<<endl;
			for(int j=0;j<ingredientes.size();j++){
				cout<<j<<") "<<ingredientes[j]->getNombre()<<endl;
				pos=j;
			}
			cout<<pos+1<<") Salir"<<endl;
			cout<<"Que desea Hacer: ";
			cin>>opcion;
			if(pos+1==opcion){
				listo=true;
			}else{
				platos[i]->setIngrediente(ingredientes[opcion]);
			}

		}while(cont==0 && listo==false);
	}
void registrar(vector<Plato*>& menu,int& dinero,vector<string>& client){
	cout<<"----------------------------------------------"<<endl;
	int resp=0,valoracion;
	string cliente;
	for (int i = 0; i < menu.size(); ++i)
	 {
	 	cout<<i<<") "<<menu[i]->getNombre()<<"- Lps."<<menu[i]->getPrecio()<<"- Valoracion: "<<menu[i]->getValoracion()<<endl;
	 } 
	 do{
	 cout<<"Que dese ordenar: ";
	 cin>> resp;
	}while(resp<0|| resp>=menu.size());
 	intinerario(menu[resp]);

	dinero+=menu[resp]->getPrecio();
	cout<<"Ingrese su Nombre: ";
	cin>>cliente;
	cout<<"Ingrese la Valoracion del Plato: ";
	cin>> valoracion;

//deberia de hacer un listado del cliente pero solo me agarra el primer string y no lo demas
	//para mostarr que compro el cliente cuanto gasto y todo eso
		string retValue;
	stringstream strStream;
	strStream<<cliente<<"--Valoracion: "
		<<valoracion<<"--Plato: "<<menu[resp]->getNombre()<<endl;
		strStream>>retValue;
	client.push_back(retValue);



	menu[resp]->setCocinado(menu[resp]->getCocinado());
	int val=menu[resp]->getValoracion();
	int nueva_valoracion= (val+valoracion)/2;
	menu[resp]->setValoracion(nueva_valoracion);
}
void verRegistro(vector<string>& cliente){
	cout<<"---------------------------------------"<<endl;
	cout<<"Registro..."<<endl;
	for (int i = 0; i < cliente.size(); ++i)
	{
		cout<<i<<") "<<cliente[i]<<endl;
	}
}
void intinerario(Plato* plato){
	for (int i = 0; i < plato->getIngredientes().size(); ++i)
	{
		if(plato->getIngrediente(i)->getCant()<0){
			do{
			int item=rand()% 3;
			//el rando agrega al intinerario del objeto por si es menor a cero
			cout<<"...";
			plato->getIngrediente(i)->setLlenado((plato->getIngrediente(i)->getLlenado())+1);
				plato->getIngrediente(i)->setCant((plato->getIngrediente(i)->getCant())+item);
			}while(plato->getIngrediente(i)->getCant()<0);

		}else{

		int a=plato->getIngrediente(i)->getDuracion();
		plato->getIngrediente(i)->setUsados((plato->getIngrediente(i)->getUsados())+1);
		int b=plato->getIngrediente(i)->getUsados();
		plato->getIngrediente(i)->setCant(  (plato->getIngrediente(i)->getCant())-1   );
		// if que verfica si ya se uso mas de la duracion para reducir 10% del Intinerario
		if(b%a==0){
			plato->getIngrediente(i)->setCant(  (plato->getIngrediente(i)->getCant())-1    );
		}
	}
	cout<<endl;
	}
}