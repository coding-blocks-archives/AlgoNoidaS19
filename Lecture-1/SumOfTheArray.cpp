// SumOfTheArray
#include <iostream>
using namespace std;
int SUM(int *a,int n){
	// base case
	if(n==0){
		return 0;
	}

	// Recursive case
	// int ChotaSum = SUM(a+1,n-1);
	// int BadaSum = a[0]+ChotaSum;
	return a[0]+SUM(a+1,n-1);
}

int main(){
	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(int);

	cout<<SUM(a,n)<<endl;


	return 0;
}