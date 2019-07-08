// WineProblem
#include <iostream>
using namespace std;
int topDown(int *wine,int i,int j,int day,int a[][100]){
	if(i>j){
		a[i][j] = 0;
		return 0;
	}

	if(a[i][j]!=-1){
		return a[i][j];
	}

	int op1 = wine[i]*day + topDown(wine,i+1,j,day+1,a);
	int op2 = wine[j]*day + topDown(wine,i,j-1,day+1,a);
	a[i][j]=max(op1,op2);
	return a[i][j];
}

int main(){
	int arr[100][100];
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			arr[i][j] = -1;
		}
	}

	int wine[]={2,3,5,1,4};
	int n=sizeof(wine)/sizeof(int);


	cout<<topDown(wine,0,n-1,1,arr)<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}