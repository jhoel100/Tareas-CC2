#include <iostream>
#include <string>

using namespace std;

template <typename t>
class Nodo{
	private:
		t * dato;
		Nodo<t> *siguiente;
	public:
		Nodo(t);
		Nodo(): dato(NULL), siguiente(NULL) {}
		~Nodo();
		void setdata(t);
		void setnext(Nodo<t> *);
		const t getdata() ;
		Nodo<t> *getnext();
		void ShowAll() ;
		bool Buscar(t) ;
		int BuscarDir(t) ;
};

template <typename t>
Nodo<t>::Nodo(t nuevo){
	siguiente = NULL;
	dato = new t;
	*dato = nuevo;
	}

template <typename t>
void Nodo<t>::setnext(Nodo<t> *s) { 
	siguiente = s; 
}

template <typename t>
Nodo<t>::~Nodo(){
	delete dato;
	siguiente = NULL;
	}

//LLamar si se uso el constructor vacio
template <typename t>
void Nodo<t>::setdata(t nuevo){
	dato = new t;
	*dato = nuevo;
	}

template <typename t>
const t Nodo<t>::getdata() const { 
	return *dato; 
	}

template <typename t>
Nodo<t> * Nodo<t>::getnext() { 
	return siguiente; 
	}

template <typename t>
void Nodo<t>::ShowAll() {
	Nodo<t> *aux = siguiente;
	cout << *dato <<" ";
	while(aux){
		cout << aux->getdata() <<" ";
		aux = aux->getnext();
	}
	cout<<endl;
}

template <typename t>
bool Nodo<t>::Buscar(t elemento) {
	Nodo<t> *aux = siguiente;
	bool bandera=true;

	if(*dato!=elemento){
		while(aux){
			if(aux->getdata()==elemento){
				return true;				
			}
			aux = aux->getnext();
		}
		return false;
	}
	else{
		return true;
	}

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
		Lista(): inicio(NULL), fin(NULL), tam(0) {}
		~Lista();
		void agregar(t);
		int gettam() ;
		bool empty() ;
		void Mostrar() ;
		void Buscar(t) ;
		void Eliminar() ;
};

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

template<typename t>
int Lista<t>::gettam(){ 
	return tam; }

template<typename t>
bool Lista<t>::empty() {
	return (inicio == NULL);
}

template<typename t>
void Lista<t>::Mostrar() {
	cout<<"El contenido de la lista es el siguiente: "<<endl;
	inicio->ShowAll(); 
}

template<typename t>
void Lista<t>::Buscar(t elemento){
	cout<<"Se encontro?: ";
	if(inicio->Nodo<t>::Buscar(elemento)==1){
		cout<<"Si se encontro "<<endl;
	} 
	else{
		cout<<"No se encontro "<<endl;
	}

	cout<<"Esta ubicado en: ";

	int ubicacion=inicio->Nodo<t>::BuscarDir(elemento);

	if(ubicacion>0){
		cout<<"Esta en la ubicacion: "<<ubicacion<<endl;
	} 
	else{
		cout<<"No esta en la lista "<<endl;
	}


}

template<typename t>
void Lista<t>::Eliminar() {
	fin->Nodo<t>::~Nodo();
}


int main(void){
	Lista<char> Caracteres;
	Lista<double> Flotantes;
	Lista<int> Enteros;

	for(int i=0;i<5;i++){
		Flotantes.agregar(((float)i)*2.25);
	}

	Caracteres.agregar('A');
	Caracteres.agregar('B');
	Caracteres.agregar('C');
	Caracteres.agregar('D');

	for(int i =0 ; i < 5; i++){
		Enteros.agregar(i);
	}

	cout<<"Ejemplos de listas simples: "<<endl;
	cout<<endl;
	cout<<"Lista de enteros: "<<endl;
	cout << "Enteros mide: " << Enteros.gettam() << endl;
	Enteros.Mostrar();
	Enteros.Eliminar();
	cout << "Enteros mide: " << Enteros.gettam() << endl;
	Enteros.Mostrar();
	cout<<endl;

	cout<<"Flotantes mide: "<<Flotantes.gettam()<<endl;
	Flotantes.Mostrar();
	cout<<endl;

	cout << "Caracteres mide: " << Caracteres.gettam() << endl;
	Caracteres.Mostrar();
	Caracteres.Buscar('C');

	return 0;
}
