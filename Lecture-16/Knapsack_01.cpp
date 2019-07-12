// Knapsack
#include <iostream>
#include <climits>
using namespace std;

int Knapsack(int* price,int *weight,int n,int capacity){
	// Base case
	if(n==0||capacity==0){
		// dp[n][capacity] = 0;
		return 0;
	}
	// if(dp[n][capacity]!=-1){
	// 	return dp[n][capacity]
	// }
	// Recursive case
	int op1=INT_MIN,op2=INT_MIN;
	if(weight[n-1]<=capacity){
		op1 = price[n-1] + Knapsack(price,weight,n-1,capacity-weight[n-1]);
	}
	op2 = 0 + Knapsack(price,weight,n-1,capacity);
	// dp[n][capacity] = max(op1,op2);
	return max(op1,op2);
}
int main(){
	int wts[]={5,6,4,7};
	int price[]={10,19,10,20};
	int capacity = 11;
	int n = 4;
	cout<<Knapsack(price,wts,n,capacity)<<endl;




	return 0;
}