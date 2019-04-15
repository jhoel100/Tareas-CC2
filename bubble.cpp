#include<iostream>

using namespace std;

void imprimir(int lista[],int longitud){
	cout<<" { ";
	for(int i=0;i<longitud;i++){
		cout<<lista[i]<<" ";
	}
	cout<<"}"<<endl;
}

void bubble(int lista[],int longitud){
	cout<<"Orden por Burbuja: "<<endl;
	int cont;
	for(int i=0;i<longitud;i++){
		for(int j=0;j<(longitud-i-1);j++){
			if(lista[j]>lista[j+1]){
				cont=lista[j];
				lista[j]=lista[j+1];
				lista[j+1]=cont;
			}
			cout<<"Paso: "<<i<<" "<<j<<endl;
			imprimir(lista,longitud);
		}
		cout<<endl;
	}
};

int main(){

	int lista[]={8,45,9,6,2,4,7,1,12,16};
	int longitud=10;
	cout<<"la lista inicial es:";
	imprimir(lista,longitud);
	//solucion es: {2,4,8,9,10,45}
	
	bubble(lista,longitud);

	//mergesort(lista,0,(longitud-1),c);
	cout<<"la lista final es:";
	imprimir(lista,longitud);

	return 0;
}
