#include <iostream>
#include <math.h>

using namespace std;
void swap ( int ** x , int ** y ) {
	int * tmp = * x ;
	*x = *y;
	* y = tmp ;}

int main(){
	int a=2;
	int b=5;
	int* c=&a;
	int* d=&b;
	int **e=&c;
	int **f=&d;

	swap(e,f);
	cout<<a<<endl;
	cout<<b<<endl;

	return 0;
}
