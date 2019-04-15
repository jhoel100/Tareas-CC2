#include <iostream>

using namespace std;

int sum ( const int numbers [] , const int numbersLen ) {
	return numbersLen == 0 ? 0 : numbers [0] + sum ( numbers + 1 ,numbersLen - 1) ; }

int main(){
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int b=10;

	cout<<sum(a,b)<<endl;
	
	return 0;
}
