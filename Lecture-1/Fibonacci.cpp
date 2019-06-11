// Fibonacii
#include <iostream>
using namespace std;
int FIBO(int n){
	// Base Case
	if(n==0||n==1){
		return n;
	}

	// Recursive case
	return FIBO(n-1)+FIBO(n-2);

}

int main(){
	int n;
	cin>>n;

	cout<<FIBO(n)<<endl;


	return 0;
}