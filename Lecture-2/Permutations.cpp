// Permutations
#include <iostream>
using namespace std;

void Permutations(char* in,int i){
	// Base Case
	if(in[i]=='\0'){
		cout<<in<<endl;
		return;
	}
	// Recursive Case
	for(int j=i;in[j]!='\0';j++){
		swap(in[j],in[i]);
		Permutations(in,i+1); 
		swap(in[j],in[i]);
	}

}


int main(){
	char in[100];
	cin>>in;

	Permutations(in,0);

	return 0;
}