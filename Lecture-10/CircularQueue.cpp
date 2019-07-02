#include <iostream>
using namespace std;

class Queue{
	int *arr;
	int n;
	int cs;
	int f;
	int e;
public:
	Queue(int s=5){
		cs = 0;
		arr = new int[s];
		n = s;
		f = 0;
		e = n-1;
	}
	void push(int d){
		if(cs == n){
			cout<<"Queue Overflow"<<endl;
		}
		else{
			e = (e+1)%n;
			arr[e] = d;
			cs++;
		}
	}

	void pop(){
		if(cs == 0){
			cout<<"Queue Underflow"<<endl;
		}
		else{
			f = (f+1)%n;
			cs--;
		}

	}

	bool empty(){
		return cs==0;
	}

	int front(){
		return arr[f];
	}
};

int main(){
	Queue q;

	q.push(0);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}
	cout<<endl;
	q.pop();


	return 0; 
}