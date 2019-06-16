// GridWays
#include <iostream>
using namespace std;

int Ways(int i,int j){
	if(i==0&&j==0){
		return 1;
	}
	if(i<0||j<0){
		return 0;
	}

	return Ways(i-1,j)+Ways(i,j-1);
}


int main(){
	int i,j;

	cin>>i>>j;

	cout<<Ways(i,j)<<endl;
	

	return 0;
}