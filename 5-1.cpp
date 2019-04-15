#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

int main(){
	srand ( time (0) ) ;
	int total=1000;
	int circulo=0;
	double y1;
	double pi;

	for(int i=0;i<total;i++){
		double x = rand () / ( double ) RAND_MAX , y = rand () / ( double ) RAND_MAX ;
		cout<<"las coordenadas son: "<<"("<<x<<","<<y<<") ";
		y1=sqrt(1-x*x);
		cout<<"con limite: "<<y1;
		if(y<y1){
			cout<<" y este SI entra"<<endl;
			circulo++;			
		}
		else{
			cout<<" este NO entra"<<endl;
		}
	}
	cout<<endl;

	cout<<"Los resultados son:"<<endl;
	cout<<"Entran: "<<circulo<<endl;
	cout<<"No entran: "<<( total-circulo)<<endl;
	pi=4.00*((double)circulo/(double)total);
	cout<<"Valor de PI: "<<pi<<endl;	
	
	return 0;
}
