#include <iostream>
#include <math.h>

using namespace std;

void printArray ( const int arr [] , const int len ) {
	for ( int i = 0; i < len ; ++ i ) {
		cout << arr [ i ];
		if ( i < len -1) {
			cout << " , " ;
		}
	}
}

int main(){
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int n=10;
	printArray(a,n);
	return 0;
}
