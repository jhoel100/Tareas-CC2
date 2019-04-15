#include <iostream>
#include <math.h>

#define LENGTH 3
#define WIDTH 3

using namespace std;
void transpose ( const int input [][ LENGTH ] , int output [][ WIDTH ]) {
	for ( int i = 0; i < WIDTH ; ++ i ) {
	for ( int j = 0; j < LENGTH ; ++ j ) {
	output [ j ][ i ] = input [ i ][ j ];
	}}};

void transpuesta(int arreglo[][3],int arreglo2[][3],int n1,int n2){
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			arreglo2[i][j]=arreglo[j][i];
		}
	}
}

void imprimir(int arreglo2[][3],int n1,int n2){
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			cout<<arreglo2[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int arreglo[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int arreglo2[3][3];
	int n1=3;
	int n2=3;
	transpuesta(arreglo,arreglo2,n1,n2);
	imprimir(arreglo2,n1,n2);	

	return 0;
}
