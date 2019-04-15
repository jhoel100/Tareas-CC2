#include<iostream>

using namespace std;

void imprimir(int lista[],int longitud){
	cout<<" { ";
	for(int i=0;i<longitud;i++){
		cout<<lista[i]<<" ";
	}
	cout<<"}"<<endl;
}

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
		cout<<"Paso: "<<inicio<<" "<<fin<<endl;
		imprimir(lista,fin+1);
	}

};

int main(){

	int lista[]={8,45,9,3,2,4};
	int longitud=6;
	int c[]={0,0,0,0,0,0};
	cout<<"la lista inicial es:";
	imprimir(lista,longitud);

	mergesort(lista,0,(longitud-1),c);
	cout<<"la lista final es:";
	imprimir(lista,longitud);

	return 0;
}
