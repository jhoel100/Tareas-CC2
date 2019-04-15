#include <iostream>

using namespace std;

int sum2(int n,int x,int y,int z,int w){
	switch (n){
	case 4:
		return w+sum2(3,x,y,z,0);
		break;
	case 3:
		return z+sum2(2,x,y,0,0);
		break;
	case 2:
		return y+sum2(1,x,0,0,0);
		break;
	case 1:
		return x;
		break;}
}

int sum ( const int x , const int y , const int z ) {
	return x + y + z ;
}
int sum ( const int a , const int b , const int c , const int d ) {
	return a + b + c + d ;
}

int main(){
	int a=10;
	int b=11;
	int c=12;
	int d=13;

	cout<<sum2(4,a,b,c,d)<<endl;
	
	return 0;
}
