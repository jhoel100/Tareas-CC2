# include <iostream>
const int ARRAY_LEN = 10;

int main () {
	int arr [ ARRAY_LEN ] = {10,9,8,10,10,10,10,10,10,1}; // Note implicit initialization of other elements
	int * xPtr = arr , *yPtr = arr + ARRAY_LEN - 1;
	std :: cout << *xPtr << " " << *yPtr ; // Should output 10 0
	return 0;
}
