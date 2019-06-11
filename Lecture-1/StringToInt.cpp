#include <iostream>
using namespace std;

string s[10]={
	"zero","one","two","three","four","five","six","seven","eight","nine"
};

void StringToInt(int n){
	if(n==0){
		return;
	}

	int digit = n%10;
	StringToInt(n/10);
	cout<<digit<<" ";	
}


int main(){
	int n;
	cin>>n;

	StringToInt(n);

	cout<<endl;
	return 0;
}