// N_Stairs
#include <iostream>
using namespace std;

int N_Stairs(int n,int k){
	// Base case 
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}

	int ans = 0;
	for(int i=1;i<=k;i++){
		ans += N_Stairs(n-i,k);
	}
	return ans;

}


int main(){
	int n,k=3;
	cin>>n;
	cout<<N_Stairs(n,k)<<endl;

	

	return 0;
}