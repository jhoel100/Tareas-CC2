#include <iostream>

using namespace std;

int sum ( const int numbers [] , const int numbersLen ) {
	int sum = 0;
	for ( int i = 0; i < numbersLen ; ++ i ) {
		sum += numbers [ i ];
	}
	return sum ; }

int main(){
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int total=10;

	cout<<sum(a,total)<<endl;
	
	return 0;
}
