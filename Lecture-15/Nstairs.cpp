// Nstairs
#include <iostream>
using namespace std;

int Stairs(int n,int k,int *dp){
	// Base case
	if(n==0){
		dp[n] = 1;
		return 1;
	}
	if(n<0){
		return 0;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	// Recursive case
	int ans = 0;
	for(int i=1;i<=k;i++){
		ans += Stairs(n-i,k,dp);
	}
	dp[n] = ans;
	return ans;
}

int BottomUp(int n,int k){
	int dp[10000]={0};
	dp[0]=1;

	for(int i=1;i<=n;i++){
		int ans = 0;
		for(int j=1;j<=k;j++){
			if(i-j>=0){
				ans += dp[i-j];
			}
		}
		dp[i]=ans;
	}
	return dp[n];
}

int Nstairs(int n,int k){
	int dp[10000];
	dp[0]=dp[1] = 1;

	for(int i=2;i<=n;i++){
		if(i-k-1>=0){
			dp[i] = 2*dp[i-1]-dp[i-k-1];
		}
		else{
			dp[i] = 2*dp[i-1];
		}
	}
	return dp[n];
}

int main(){
	int n,k=3;
	cin>>n;
	int dp[10000];
	for(int i=0;i<10000;i++){
		dp[i] = -1;
	}
	cout<<Stairs(n,k,dp)<<endl;
	cout<<BottomUp(n,k)<<endl;
	cout<<Nstairs(n,k)<<endl;
	
	return 0;
}