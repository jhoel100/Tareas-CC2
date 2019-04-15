#include <iostream>

using namespace std;

int sum ( const int a , const int b , const int c = 0 , const int d = 0)
{
	return a + b + c + d ;
}

int main(){
	int a=10;
	int b=11;
	int c=12;
	int d=13;

	cout<<sum(a,b)<<endl;
	
	return 0;
}
