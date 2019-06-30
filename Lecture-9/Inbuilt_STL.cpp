// Stack
#include <iostream>
#include <stack>
using namespace std;

void Print(stack<char> s){
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}

int main(){
	stack<char> s;

	s.push('A');
	s.push('B');
	s.push('C');
	// s.push(3);
	// s.push(4);

	Print(s);
	Print(s);






	return 0; 
}