// CurrencyExchange
#include <iostream>
#include <climits>
using namespace std;

int topDown(int n,int *coins,int coins_size,int* arr){
	// Base case
	if(n==0){
		arr[n] = 0;
		return 0;
	}
	if(arr[n]!=-1){
		return arr[n];
	}
	int ans = INT_MAX;
	for(int i=0;i<coins_size;i++){
		if(n-coins[i]>=0){
			int smallerAns = topDown(n-coins[i],coins,coins_size,arr);
			if(smallerAns!=INT_MAX){
				ans = min(ans,smallerAns+1);
			}
		}
	}
	arr[n] = ans;
	return ans;
}

int BottomUp(int amount,int* coins,int n){
	int *arr = new int[amount+1];

	for(int i=0;i<=amount;i++){
		arr[i] = INT_MAX;
	}
	arr[0] = 0;

	for(int rupay=1;rupay<=amount;rupay++){
		for(int i=0;i<n;i++){
			if(rupay-coins[i]>=0){
				arr[rupay] = min(arr[rupay],arr[rupay-coins[i]]+1);
			}
		}
	}
	for(int i=0;i<=amount;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return arr[amount];

}

int main(){
	int n;
	cin>>n;
	int coins[]={1,7,10};
	int coins_size = sizeof(coins)/sizeof(int);
	int arr[100000];
	for(int i=0;i<100000;i++){
		arr[i]= -1;
	}	
	cout<<BottomUp(n,coins,coins_size)<<endl;
	cout<<topDown(n,coins,coins_size,arr)<<endl;

	return 0;
}