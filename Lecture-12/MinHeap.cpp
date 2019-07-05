// MinHeap
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Minheap{
	vector<int> v;

	void heapify(int i){
		int min_index = i;
		int left_child = 2*i;
		int right_child = left_child + 1;

		if(left_child<v.size() && v[min_index]>v[left_child]){
			min_index = left_child;
		}
		if(right_child<v.size() && v[min_index]>v[right_child]){
			min_index = right_child;
		}

		if(min_index!=i){
			swap(v[min_index],v[i]);
			heapify(min_index);
		}

	}

public:
	Minheap(){
		v.push_back(-1);
	}

	void push(int d){
		v.push_back(d);
		int children = v.size()-1;
		int parent = children/2;
		while(children>1 && v[parent]>v[children]){
			swap(v[children],v[parent]);
			children = parent;
			parent = parent/2;
		}
	}

	void pop(){
		swap(v[1],v[v.size()-1]);
		v.pop_back();

		heapify(1);
	}

	int top(){
		return v[1];
	}

	bool empty(){
		return v.size()==1;
	}

};


class Comparator{
public:
	bool operator()(int a,int b){ // Functor
		return a>b;
	}
};

void Print(priority_queue<int,vector<int>,Comparator> h){
	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}	
	cout<<endl;
}
bool Meracomparator(int a,int b){
	cout<<a<<" "<<b<<endl;
	return a<b;
}

int main(){
	// Minheap h;
	int arr[]={5,4,32,1,1};
	int n=sizeof(arr)/sizeof(int);

	sort(arr,arr+n,Meracomparator);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	priority_queue<int,vector<int>,Comparator> h;
	int k =3;
	int number;
	int size = 1;
	// while(1){
	// 	cin>>number;
	// 	if(number == -1){
	// 		// Print the heap
	// 		Print(h);
	// 	}
	// 	else{
	// 		if(size<=k){
	// 			// Insert in heap
	// 			h.push(number);
	// 			size++;
	// 		}
	// 		else{
	// 			// Check and then push
	// 			if(h.top()<number){
	// 				h.pop();
	// 				h.push(number);
	// 			}
	// 		}
	// 	}
	// }
	h.push(10);
	h.push(2);
	h.push(5);
	h.push(0);
	h.push(6);
	h.push(8);
	h.push(1);


	while(!h.empty()){
		cout<<h.top()<<endl;
		h.pop();
	}









	return 0;
}