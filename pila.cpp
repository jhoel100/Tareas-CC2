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
class Pila{
	private:
		Nodo<t> *inicio;
		Nodo<t> *fin;
		int tam;
	public:
		Pila();
		~Pila();
		void agregar(t);
		int gettam() ;
		bool empty() ;
		void Mostrar() ;
		void Buscar(t) ;
		void Eliminar() ;
		Nodo<t>* GetElemento(int);

		Nodo<t> * getinicio(){
			return inicio;
		}
		Nodo<t> * getfin(){
			return fin;
		}

		void sacar(){
			cout<<"Se ha sacado un elemento: "<<endl;
			Nodo<t>* auxiliar;
			auxiliar=GetElemento(1);
			cout<<"Su contenido es: "<<auxiliar->getdata()<<endl;
			Eliminar();
			
		}

    class Iterator{
        Nodo<t> *nodolista;
     public:
        Iterator(){}
        bool operator != (Nodo<t>* entrada)
        {         
            return (nodolista != entrada);
        }

			Nodo<t>& operator*()
        {
            return *nodolista;
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
Pila<t>::Pila() {
	inicio=NULL;
	fin=NULL;
	tam=0;
}

template<typename t>
void Pila<t>::Mostrar() {
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
int Pila<t>::gettam() { 
	return tam; }

template<typename t>
bool Pila<t>::empty() {
	return (inicio == NULL);
}

template<typename t>
void Pila<t>::Buscar(t elemento) {

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

template<typename t>
Nodo<t>* Pila<t>::GetElemento(int numero) {
	Nodo<t> *aux = inicio;
	Nodo<t> *aux2;
	Nodo<t> *anterior;

	int cont=1;

	if(tam>=numero){
		while(numero>=cont){
			if(cont==numero){
				aux2=aux->getnext();
				return aux;
				anterior->setnext(aux2);
			}
			anterior=aux;
			aux = aux->getnext();
			cont=cont+1;
		}
		return NULL;
	}
	return NULL;
}

template<typename t>
void Pila<t>::Eliminar() {
	cout<<"Se elimino un elemento"<<endl;
	Nodo<t> *aux = inicio;
	Nodo<t> *aux2;

	aux2=aux->getnext();
	delete aux;
	inicio=aux2;
	tam--;
}

template<typename t>
Pila<t>::~Pila(){
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
void Pila<t>::agregar(t nuevo){
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

	Pila<int> Enteros;

	for(int i =0 ; i < 10; i++){
		Enteros.agregar(i+1);
	}

	cout<<"Ejemplos de listas simples: "<<endl;
	cout<<endl;
	cout<<"Lista de enteros: "<<endl;
	cout << "Enteros mide: " << Enteros.gettam() << endl;
	Enteros.Mostrar();
	cout<<endl;

	Enteros.sacar();
	cout<<endl;
	Enteros.sacar();
	cout<<endl;
	Enteros.sacar();
	cout<<endl;
	Enteros.Mostrar();

	return 0;
}
