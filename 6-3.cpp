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

int main(){

	return 0;
}
