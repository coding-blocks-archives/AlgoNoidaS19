// Vector_Stack
#include <iostream>
#include <vector>
using namespace std;

class Stack{
	vector<int> v;
public:
	void push(int d){
		v.push_back(d);
	}

	void pop(){
		v.pop_back();
	}

	int top(){
		return v[v.size()-1];
	}

	bool empty(){
		return v.size() == 0;
	}
};

void Print(Stack s){
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}

int main(){
	Stack s;
	s.push(0);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	Print(s);


	return 0; 
}