#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n=10;
	int dartsInCircle = 0;
	for ( int i = 0; i < n ; ++ i ) {
		double x = rand () / ( double ) RAND_MAX , y = rand () / ( double )RAND_MAX ;
		if ( sqrt ( x * x + y * y ) < 1 ) {
			++ dartsInCircle ;
		} }
	cout<<dartsInCircle<<endl;
	return 0;
}
