// BalancedOrNot
#include <iostream>
#include <stack>
using namespace std;
bool isBalanced(char *in){
	stack<char> s;

	for(int i=0;in[i]!='\0';i++){
		char ch = in[i];
		switch(ch){
			case '(':
			case '[':
			case '{':
					s.push(ch);
					break;
			case '}': 
					if(!s.empty() && s.top()=='{'){
						s.pop();
					}
					else{
						return false;
					}
					break;
			case ')':
					if(!s.empty() && s.top()=='('){
						s.pop();
					}
					else{
						return false;
					}
					break;
			case ']':
					if(!s.empty() && s.top()=='['){
						s.pop();
					}
					else{
						return false;
					}
		}
	}	
	if(s.empty()==true){
		return true;
	}
	else{
		return false;
	}

}

int main(){
	char in[100] = "{a+(b+c)*d+[e+f]/g}}";

	if(isBalanced(in)){
		cout<<"Balanced"<<endl;
	}
	else{
		cout<<"Not Balanced"<<endl;
	}


	return 0; 
}