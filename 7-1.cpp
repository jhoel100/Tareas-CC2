#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int stringLength ( string str ) {
	int length = 0;
	while (str[length] != '\0') {++ length ;}
	return length ;
	}

int main(){
	string palabra="hola como estas";
	cout<<stringLength(palabra)<<endl;
	return 0;
}
