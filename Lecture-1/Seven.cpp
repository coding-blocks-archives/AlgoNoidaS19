// Seven
#include <iostream>
using namespace std;
int First7(int *a,int n,int i){
	// Base Case
	if(i==n){
		return -1;
	}
	// Recursive Case
	if(a[i]==7){
		return i;
	}
	return First7(a,n,i+1);
}

bool Check7(int *a,int n){
	if(n==0){
		return false;
	}

	if(a[0]==7){
		return true;
	}
	return Check7(a+1,n-1);
}

int last7(int* a,int n,int i){
	// base case
	if(i==n){
		return -1;
	}
	if(a[i]==7){
		int ChotaIndex = i;
		int BadaIndex = last7(a,n,i+1);
		if(BadaIndex>ChotaIndex){
			return BadaIndex;
		}
		else{
			return ChotaIndex;
		}
	}
	return last7(a,n,i+1);
}


int main(){
	int a[]={1,2,7,6,7,7,8};
	int n=sizeof(a)/sizeof(int);

	cout<<last7(a,n,0)<<endl;


	return 0;
}