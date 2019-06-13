#include <iostream>
using namespace std;

int StringToInt(char *a, int n){
	// Base case
	if(n==0){
		return 0;
	}
	// Recursive case
	int last_digit = a[n-1]-'0';
	return StringToInt(a,n-1)*10+last_digit;
}


int main(){
	char a[100];
	cin>>a;
	int n = strlen(a);
	cout<<StringToInt(a,n)*10<<endl;

	return 0;
}