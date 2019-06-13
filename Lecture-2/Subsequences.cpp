// Subsequences
#include <iostream>
using namespace std;

void Subsequences(char* in,int i,char* out,int j){
	// Base case
	if(in[i]=='\0'){
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
	// Recursive case
	// Ek baari ignore kro
	Subsequences(in,i+1,out,j);

	// Ek baari consider krlo
	out[j] = in[i];
	Subsequences(in,i+1,out,j+1);
}


int main(){
	char in[100];
	char out[100];
	cin>>in;
	Subsequences(in,0,out,0);

	return 0;
}