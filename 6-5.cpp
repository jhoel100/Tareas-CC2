#include <iostream>
#include <math.h>

using namespace std;
void reverse ( int numbers [] , const int numbersLen ) {
	for ( int i = 0; i < numbersLen / 2; ++ i ) {
	int tmp = *( numbers + i ) ;
	int indexFromEnd = numbersLen - i - 1;
	*( numbers + i ) = *( numbers + indexFromEnd ) ;
	*( numbers + indexFromEnd ) = tmp ;
	} }

int main(){
	int a[]={1,2,3,4,5};
	int l=5;
	reverse(a,l);
	return 0;
}
