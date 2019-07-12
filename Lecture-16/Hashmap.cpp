// Hashmap
#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main(){
	map<string,int> h;

	// for insertion : insert
	h.insert(make_pair("Mango",100));
	h.insert(make_pair("Apple",150));

	
	pair<string,int> p("Banana",45);// p.first-- Banana, p.second--45
	h.insert(p);

	h["Kiwi"] = 60;
	h["Papaya"] = 40;

	// for each loop - for each node belonging to hashmap h
	for(auto node:h){
		// to get the key - node.first, node.second - value
		cout<<node.first<<"-->"<<node.second<<endl;
	}


	return 0;
}