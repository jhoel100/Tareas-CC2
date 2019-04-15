# include <iostream>

//Dos soluciones, subir la funcion antes del main, o definir la misma sin contenido al inicio. 

void printNum(int);

int main () {
	printNum (35) ;
	return 0;
}

void printNum ( int number ) { std :: cout << number ; }
