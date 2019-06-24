// Vector
#include <iostream>
using namespace std;

class Vector{
public:
	int *arr;
	int cs;
	int ms;

	Vector(int n=2){
		arr = new int[n];
		cs = 0;
		ms = n;
	}

	void push_back(int data){
		if(cs==ms){
			int *oldarr = arr;
			int oldms = ms;
			
			arr = new int[2*ms];
			ms = 2*ms;
			for(int i=0;i<oldms;i++){
				arr[i] = oldarr[i];
			}
			delete []oldarr;
		}
		arr[cs] = data;
		cs++;
	}

	void pop_back(){
		if(cs>0){
			cs--;
		}
	}

	int operator[](int i){
		return arr[i];
	}

	int size(){
		return cs;
	}

	int capacity(){
		return ms;
	}

};

int main(){
	Vector v;

	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	// v.pop_back();
	// v.pop_back();

	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}

	cout<<endl;
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl;


	return 0; 
}