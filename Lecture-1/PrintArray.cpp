// PrintArray
#include <iostream>
using namespace std;

void Print(int *a,int n){
	// Base case
	if(n==0){
		return;
	}
	// Recursive Case
	cout<<a[0]<<" ";
	Print(a+1,n-1);
}

void Print1(int *a,int n){
	if(n==0){
		return;
	}
	cout<<a[n-1]<<" ";
	Print1(a,n-1);
}

void Print2(int *a,int n,int i){
	if(i==n){
		return;
	}

	cout<<a[i]<<" ";
	Print2(a,n,i+1);
}

int main(){
	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(int);

	Print(a,n);
	cout<<endl;
	Print1(a,n);
	cout<<endl;
	Print2(a,n,0);
	cout<<endl;
	return 0;
}