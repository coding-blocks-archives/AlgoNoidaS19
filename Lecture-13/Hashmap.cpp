// Hashmap
#include <iostream>
using namespace std;
template<typename T>
class node{
public:
	string key;
	T value;
	node<T>* next;
	node(string key,T value){
		this->key = key;
		this->value = value;
		next = NULL;
	}
};

template<typename T>
class hashmap{
	node<T>** Bucket;
	int ts;
	int cs;

	int hashFn(string key){
		int ans = 0;
		int mul_factor = 1;
		for(int i=0;key[i]!='\0';i++){
			ans +=key[i]*mul_factor;
			mul_factor*=37;
			ans %= ts;
			mul_factor %= ts;
		}
		return ans%ts;
	}
public:
	hashmap(int s=7){
		ts = s;
		Bucket = new node<T>*[ts];
		cs = 0;

		for(int i=0;i<ts;i++){
			Bucket[i] = NULL;
		}
	}

	void rehash(){
		node<T>** oldBucket;
		oldBucket = Bucket;
		int oldts = ts;

		Bucket = new node<T>*[2*ts];
		ts = 2*ts;
		cs = 0;
		for(int i=0;i<ts;i++){
			Bucket[i] = NULL;
		}

		for(int i=0;i<oldts;i++){
			node<T>* temp = oldBucket[i];

			while(temp){
				insert(temp->key,temp->value);
				temp=temp->next;
			}
			delete oldBucket[i];
		}
		delete []oldBucket;
	}

	void insert(string key,T value){
		int i = hashFn(key);

		node<T>* n = new node<T>(key,value);
		n->next = Bucket[i];
		Bucket[i] = n;
		cs++;

		float load_factor = cs/(ts*1.0);
		if(load_factor>0.7){
			rehash();
		}
	}

	T* search(string key){
		int i = hashFn(key);
		node<T>* temp = Bucket[i];
		while(temp){
			if(temp->key == key){
				return &(temp->value);
			}
			temp=temp->next;
		}
		return NULL;
	}

	T& operator[](string key){
		T* temp = search(key); // 100
		if(temp==NULL){
			T garbage;
			insert(key,garbage);
			temp = search(key);
			return *temp;
		}
		else{
			return *temp;
		}
	}

	void remove(string key){
		int i = hashFn(key);
	}

	void Print(){
		for(int i=0;i<ts;i++){
			node<T>* temp=Bucket[i];
			cout<<i<<"->";
			while(temp){
				cout<<"("<<temp->key<<","<<temp->value<<")";
				temp=temp->next;
			}
			cout<<endl;
		}
		cout<<endl;
	}

};

int main(){
	hashmap<int> h;

	h.insert("Mango",100);
	h.insert("Apple",180);
	h.insert("Pineapple",50);
	// h.insert("Kiwi",60);
	h["Kiwi"] = 60; // Insertion
	h["Banana"] = 50; // Insertion
	h["Banana"] = 500; // Updation
	h.Print();
	cout<<h["Banana"]<<endl; // Search
	cout<<h["Mango"]<<endl; // Search







	return 0;
}