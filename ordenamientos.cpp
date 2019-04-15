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
	cout<<"Orden por Insersion: ";
	int val,j;
	for(int i=1;i<longitud;i++){
		val=lista[i];
		j=i-1;
		while(j>=0 && val<lista[j]){
			lista[j+1]=lista[j];
			j=j-1;
		}
		lista[j+1]=val;
	}
	imprimir(lista,longitud);
	
};

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
		quicksort(lista,inicio,q-1);
		quicksort(lista,q+1,fin);}

};

void corr(int lista[]){
	int comd;
	comd=lista[0];
	lista[0]=lista[1];
	lista[1]=comd;
};

void bubble(int lista[],int longitud){
	cout<<"Orden por Burbuja: ";
	int cont;
	for(int i=0;i<longitud;i++){
		for(int j=0;j<(longitud-i);j++){
			if(lista[j]>lista[j+1]){
				cont=lista[j];
				lista[j]=lista[j+1];
				lista[j+1]=cont;
			}
		}
	}
	imprimir(lista,longitud);
};

void mezcla(int list[],int inicio,int m,int fin,int c[]){
	int p=inicio;
	int q=m+1;
	int r=inicio;
	while(p<=m && q<=fin){
		if(list[p]<list[q]){
			c[r]=list[p];
			p=p+1;}
		else{
			c[r]=list[q];
			q=q+1;}
		r=r+1;}
	while(p<=m){
		c[r]=list[p];
		p=p+1;
		r=r+1;}
	while(q<=fin){
		c[r]=list[q];
		q=q+1;
		r=r+1;
	}	
};

void mergesort(int lista[],int inicio,int fin,int c[]){
	int m;
	if(inicio!=fin){
		m=(inicio+fin)/2;
		mergesort(lista,inicio,m,c);
		mergesort(lista,m+1,fin,c);
		mezcla(lista,inicio,m,fin,c);
		for(int k=inicio;k<=fin;k++){
			lista[k]=c[k];
		}
	}

};

int main(){

	int lista[]={8,45,9,8,2,4};
	int longitud=6;
	int c[]={0,0,0,0,0,0};
	cout<<"la lista inicial es:";
	imprimir(lista,longitud);
	//solucion es: {2,4,8,9,10,45}

	//insertionsort(lista,longitud);


	cout<<"Quicksort: ";
	quicksort(lista,0,(longitud-1));
	//corr(lista);
	
	//bubble(lista,longitud);

	//mergesort(lista,0,(longitud-1),c);

	imprimir(lista,longitud);

	return 0;
}
