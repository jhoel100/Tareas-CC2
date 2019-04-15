#include<iostream>

using namespace std;

void imprimir(int lista[],int longitud){
	cout<<" { ";
	for(int i=0;i<longitud;i++){
		cout<<lista[i]<<" ";
	}
	cout<<"}"<<endl;
}

int partition(int lista[],int inicio,int fin){
	int x=lista[fin];
	int i=inicio-1;
	int comd;
	for(int j=inicio;j<=(fin-1);j++){
		if(lista[j]<=x){
			i=i+1;
			comd=lista[i];
			lista[i]=lista[j];
			lista[j]=comd;			
		}
	comd=lista[i+1];
	lista[i+1]=lista[fin];
	lista[fin]=comd;
	}
	return (i+1);

};

void quicksort(int lista[],int inicio,int fin){
	if(inicio<fin){
		int q=partition(lista,inicio,fin);
		cout<<"particion: "<<q<<" limites "<<inicio<<" "<<fin<<endl;
		quicksort(lista,inicio,q-1);
		quicksort(lista,q+1,fin);}
		imprimir(lista,fin+1);

};

void corr(int lista[]){
	int comd;
	comd=lista[0];
	lista[0]=lista[1];
	lista[1]=comd;
};

int main(){

	int lista[]={8,45,9,6,2,4,15,42};
	int longitud=8;
	int c[]={0,0,0,0,0,0};
	cout<<"la lista inicial es:";
	imprimir(lista,longitud);

	quicksort(lista,0,(longitud-1));

	cout<<"la lista final es:";
	imprimir(lista,longitud);

	return 0;
}
