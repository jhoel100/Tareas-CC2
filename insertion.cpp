#include<iostream>

using namespace std;

void imprimir(int lista[],int longitud){
	cout<<" { ";
	for(int i=0;i<longitud;i++){
		cout<<lista[i]<<" ";
	}
	cout<<"}"<<endl;
}

void insertionsort(int lista[] ,int longitud){
	cout<<"Orden por Insersion: "<<endl;
	int val,j;
	for(int i=1;i<longitud;i++){
		val=lista[i];
		j=i-1;
		while(j>=0 && val<lista[j]){
			lista[j+1]=lista[j];
			cout<<"paso de j: "<<j<<endl;
			imprimir(lista,longitud);
			j=j-1;
		}
		lista[j+1]=val;
		cout<<"paso de reemplazo: "<<endl;
		imprimir(lista,longitud);
		cout<<endl;
	}

	
};

int main(){

	int lista[]={8,45,9,6,2};
	int longitud=5;
	int c[]={0,0,0,0,0};
	cout<<"la lista inicial es:";
	imprimir(lista,longitud);
	cout<<endl;
	//solucion es: {2,4,8,9,10,45}

	insertionsort(lista,longitud);
	imprimir(lista,longitud);

	return 0;
}
