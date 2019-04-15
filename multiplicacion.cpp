#include<iostream>

using namespace std;

void imprimir(int matriz[][3],int ii,int jj){
	for(int i=0;i<ii;i++){
		for(int j=0;j<jj;j++){
			cout<<matriz[i][j]<<"   ";
		}
		cout<<endl;
	}
}

void multiplicar(int matriz1[][2],int matriz2[][3],int matriz3[][3],int ii,int jj,int kk){
	int sum=0;
	for(int i=0;i<ii;i++){
		for(int k=0;k<kk;k++){
			for(int j=0;j<jj;j++){
				sum+=matriz1[i][j]*matriz2[j][k];
			}
			matriz3[i][k]=sum;
			sum=0;}
	}
};

int main(){

	int matriz1[][2]={{1,2},{3,4},{5,6}};
	int matriz2[][3]={{1,2,3},{4,5,6}};
	int matriz3[][3]={{0,0,0},{0,0,0},{0,0,0}};
	int i=3;
	int j=2;
	int k=3;

	multiplicar(matriz1,matriz2,matriz3,i,j,k);
	imprimir(matriz3,3,3);

	return 0;
}
