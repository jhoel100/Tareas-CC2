#include <iostream>
#include <string>

using namespace std;

template <typename t>
class Nodo{
	private:
		t dato;
		Nodo<t> *siguiente;
	public:
		Nodo(t);
		Nodo();
		~Nodo();

		void setdata(t);
		void setnext(Nodo<t> *);
		const t getdata() ;
		Nodo<t> *getnext();
		int BuscarDir(t) ;
		Nodo<t> *getDir();
};

template <typename t>
Nodo<t>::Nodo(){
	siguiente = NULL;
	dato = NULL;
	}

template <typename t>
Nodo<t>::Nodo(t nuevo){
	siguiente = NULL;
	dato = nuevo;
	}

template <typename t>
void Nodo<t>::setnext(Nodo<t> *s) { 
	siguiente = s; 
}

template <typename t>
Nodo<t>::~Nodo(){
	siguiente = NULL;
	}

//LLamar si se uso el constructor vacio
template <typename t>
void Nodo<t>::setdata(t nuevo){
	dato = nuevo;
	}

template <typename t>
const t Nodo<t>::getdata(){ 
	return dato; 
	}

template <typename t>
Nodo<t> * Nodo<t>::getnext() { 
	return siguiente;
	}

template <typename t>
Nodo<t> * Nodo<t>::getDir() { 
	return this; 
	}

template <typename t>
int Nodo<t>::BuscarDir(t elemento) {
	Nodo<t> *aux = siguiente;
	int ubicacion=1;

	if(*dato!=elemento){
		while(aux){
			if(aux->getdata()==elemento){
				return (ubicacion+1);				
			}
			aux = aux->getnext();
			ubicacion=ubicacion+1;
		}
		return -1;
	}
	else{
		return ubicacion;
	}

}


template <class t>
class Lista{
	private:
		Nodo<t> *inicio;
		Nodo<t> *fin;
		int tam;
	public:
		Lista();
		~Lista();
		void agregar(t);
		int gettam() ;
		bool empty() ;
		void Mostrar() ;
		void Buscar(t) ;
		void Eliminar(int) ;
		Nodo<t> * getinicio(){
			return inicio;
		}
		Nodo<t> * getfin(){
			return fin;
		}

    class Iterator{
        Nodo<t> *nodolista;
     public:
        Iterator(){}
        bool operator != (Nodo<t>* o)
        {         
            return (nodolista != o);
        }
        Iterator& operator=(Nodo<t> *igual)
        {
            nodolista=igual;
            return *this;
        }
        Iterator& operator ++()
        {
            nodolista=nodolista->getnext();
            return *this;
        }

        t getvalor(){return (nodolista->getdata());}

    };

};

template<typename t>
Lista<t>::Lista() {
	inicio=NULL;
	fin=NULL;
	tam=0;
}

template<typename t>
void Lista<t>::Mostrar() {
	cout<<"El contenido de la lista es el siguiente: "<<endl;
	cout << inicio->getdata() <<" ";
	Nodo<t> *aux = inicio->getnext();
	while(aux){
		cout << aux->getdata() <<" ";
		aux = aux->getnext();
	}
	cout<<endl;
}

template<typename t>
int Lista<t>::gettam() { 
	return tam; }

template<typename t>
bool Lista<t>::empty() {
	return (inicio == NULL);
}

template<typename t>
void Lista<t>::Buscar(t elemento) {

	Nodo<t> *aux = inicio->getDir();
	int pos=1;
	bool flag=false;

	if(aux->getdata()!=elemento){
		while(aux){
			
			if(aux->getdata()==elemento){
				cout<<"Se encuentra en la ubicacion "<<pos<<endl;
				flag=true;			
			}
			aux = aux->getnext();
			pos++;
		}
		if(flag==false){
			cout<<"No se encontro"<<endl;
		}
	}
	else{
		cout<<"Se encuentra en la ubicacion "<<pos<<endl;
	}

}


//Falta corregir eleminicar
template<typename t>
void Lista<t>::Eliminar(int numero) {
	cout<<"Se elimino el elemento de posicion "<<numero<<endl;
	Nodo<t> *aux = inicio;
	Nodo<t> *aux2;
	Nodo<t> *anterior;

	int cont=1;

	if(tam>=numero){
		while(numero>=cont){
			if(cont==numero){
				aux2=aux->getnext();
				delete aux;
				anterior->setnext(aux2);
			}
			anterior=aux;
			aux = aux->getnext();
			cont=cont+1;
		}
		tam--;
	}
}

template<typename t>
Lista<t>::~Lista(){
	Nodo<t> *aux = inicio;
	if(!empty()){
		while(inicio){
			inicio = inicio->getnext();
			delete aux;
			aux = inicio;
		}
	}
	fin = NULL;
	tam = 0;
}

template<typename t>
void Lista<t>::agregar(t nuevo){
	Nodo<t> *aux = new Nodo<t>(nuevo);
	if(empty()){
		inicio = aux;
	}else{
		fin->setnext(aux);
	}
	fin = aux;
	tam++;
}

int main(void){
	Lista<char> Caracteres;
	Lista<double> Flotantes;
	Lista<int> Enteros;

	for(int i=0;i<10;i++){
		Flotantes.agregar(((float)i)*2.25);
	}

	Caracteres.agregar('A');
	Caracteres.agregar('B');
	Caracteres.agregar('C');
	Caracteres.agregar('D');
	Caracteres.agregar('E');
	Caracteres.agregar('F');
	Caracteres.agregar('G');
	Caracteres.agregar('H');

	for(int i =0 ; i < 10; i++){
		Enteros.agregar(i+1);
	}

	cout<<"Ejemplos de listas simples: "<<endl;
	cout<<endl;
	cout<<"Lista de enteros: "<<endl;
	cout << "Enteros mide: " << Enteros.gettam() << endl;
	Enteros.Mostrar();
	cout<<endl;
	Enteros.Eliminar(4);
	cout << "Enteros mide: " << Enteros.gettam() << endl;
	Enteros.Mostrar();
	cout<<endl;

	cout<<"Flotantes mide: "<<Flotantes.gettam()<<endl;
	Flotantes.Mostrar();
	cout<<endl;

	cout << "Caracteres mide: " << Caracteres.gettam() << endl;
	Caracteres.Mostrar();
	Caracteres.Buscar('G');
	cout<<endl;

	cout<<"Esta es la lista de elementos: "<<endl;
	Lista<int>::Iterator iterador;
    for(iterador=Enteros.getinicio(); iterador!=Enteros.getfin();iterador.operator++())
     { 
       cout<<(iterador.getvalor())<<" ";       
     }
		cout<<endl;

	return 0;
}
