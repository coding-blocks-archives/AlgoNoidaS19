// Stack
#include <iostream>
#include "Stack.h"
using namespace std;
void Print(Stack<int> s){
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}

int main(){
	Stack<int> s;

	s.push(0);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	// s.push('A');
	// s.push('B');
	// s.push('C');
	Print(s);
	






	return 0; 
}