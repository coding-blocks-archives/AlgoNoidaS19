// Vector
#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> v;

	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.pop_back();
	v.pop_back();

	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}

	cout<<endl;
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl;



	return 0; 
}