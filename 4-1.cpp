#include <iostream>

using namespace std;

int sum( const int x , const int y ) {
	return x + y ;
}

double sum( const double x , const double y ) {
	return x + y ;
}

int main(){
	int a=10;
	int b=12;
	double c=19;
	double d=24;

	cout<<sum(a,b)<<endl;
	cout<<sum(c,d)<<endl;	
	return 0;
}
