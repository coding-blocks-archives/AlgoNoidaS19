// Fibonacci
#include <iostream>
using namespace std;

int fibo(int n){
	if(n==0||n==1){
		return n;
	}

	return fibo(n-1)+fibo(n-2);
}

int fibo1(int n,int *arr){
	if(n==0||n==1){
		arr[n] = n;
		return n;
	}
	if(arr[n]!=-1){
		return arr[n];
	}
	int ans=fibo1(n-1,arr)+fibo1(n-2,arr);
	arr[n] = ans;
	return ans;
}

int BottomUp(int n){
	int *arr = new int[n+1];
	// Initialization
	arr[0] = 0;
	arr[1] = 1;

	for(int i=2;i<=n;i++){
		arr[i] = arr[i-1]+arr[i-2];
	} 
	// for(int i=2;i<=n;i++){
	// 	cout<<arr[i]<<" ";
	// }	
	// cout<<endl;
	return arr[n];
}

int main(){
	int n;
	cin>>n;
	int arr[100000];
	for(int i=0;i<100000;i++){
		arr[i]= -1;
	}
	cout<<BottomUp(n)<<endl;
	cout<<fibo1(n,arr)<<endl;
	cout<<fibo(n)<<endl;

	return 0;
}