// DynamicMemoryAllocation
#include <iostream>
using namespace std;

int* fun(int n){
	int *a = new int[n];
	for(int i=0;i<n;i++){
		a[i] = i;
	}

	// for(int i=0;i<n;i++){
	// 	cout<<a[i]<<" ";
	// }
	// cout<<endl;
	return a;
}






int main(){
	int rows,cols;
	cin>>rows>>cols;

	int ** a = new int*[rows];

	for(int i=0;i<rows;i++){
		a[i] = new int[cols]; // a[i] = *(a+i)
	}
	int number =1;
	for(int i = 0;i<rows;i++){
		for(int j=0;j<cols;j++){
			a[i][j] = number;
			number ++;
		}
	}
	for(int i = 0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

	for(int i=0;i<rows;i++){
		delete []a[i];
	}

	delete []a;





	// int *a = new int;

	// *a = 10;
	// cout<<*a<<endl;

	// delete a;

	// int n;
	// cin>>n;
	// int * arr=fun(n);
	// for(int i=0;i<n;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// delete []arr;
	// arr =NULL;
	// cout<<endl;

	

	return 0; 
}