// Generic_AdjList
#include <iostream>
#include <map>
#include <unordered_map>
#include <list>
#include <queue>
#include <climits>
using namespace std;
template<typename T>
class Graph{
	map<T,list<T> > adjList;

	void DFSHelper(T src,map<T,bool> &visited){
		cout<<src<<", ";
		visited[src] = true;

		for(auto children:adjList[src]){
			if(!visited[children]){
				DFSHelper(children,visited);
			}
		}
	}
public:
	void addEdge(T u,T v,bool bidir = true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}

	void Print(){
		for(auto node:adjList){
			cout<<node.first<<"-->";
			for(auto neighbours:node.second){
				cout<<neighbours<<",";
			}
			cout<<endl;
		}
	}

	void BFS(T src){
		queue<T> q;
		unordered_map<T,bool> visited;
		q.push(src);
		visited[src] = true;
		while(!q.empty()){
			T node = q.front();
			q.pop();
			cout<<node<<",";
			for(auto neighbours:adjList[node]){
				if(!visited[neighbours]){
					q.push(neighbours);
					visited[neighbours] = true;
				}
			}
		}
		cout<<endl;
	}

	int SSSP(T src,T des){
		map<T,int> dist;
		map<T,T> parent;
		
		for(auto node:adjList){
			dist[node.first] = INT_MAX;
		}
		queue<T> q;
		dist[src] = 0;
		parent[src] = src;
		q.push(src);
		while(!q.empty()){
			T node = q.front();
			q.pop();
			int parent_dist = dist[node];
			for(auto children:adjList[node]){
				if(dist[children] == INT_MAX){
					dist[children] = parent_dist + 1;
					parent[children] = node;
					q.push(children);
				}	
			}
		}
		for(auto node:dist){
			cout<<"Distance of "<<node.first<<" from "<<src<<" is "<<node.second<<endl;
		}
		T temp = des;

		while(temp!=src){
			cout<<temp<<"<--";
			temp = parent[temp];
		}
		cout<<src<<endl;

		return dist[des];
	}



	void DFS(T src){
		map<T,bool> visited;
		int component = 1;

		DFSHelper(src,visited);
		// cout<<endl;

		for(auto node:adjList){
			if(!visited[node.first]){
				component ++;
				DFSHelper(node.first,visited);
			}
		}
		cout<<endl;
		cout<<"No of component : "<<component<<endl;
	}
};

int main(){
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(4,2);
	g.addEdge(3,2);
	g.addEdge(3,4);
	g.addEdge(3,5);

	g.addEdge(10,5);
	g.addEdge(15,10);
	g.addEdge(15,200);
	g.addEdge(160,200);

	g.DFS(0);
	// cout<<g.SSSP(0,5)<<endl;

	// int board[50] = {0};
	// board[2] = 13;
	// board[5] = 2;
	// board[9] = 18;
	// board[18] = 11;
	// board[17]=-13;
	// board[20] = -14;
	// board[24] = -8;
	// board[25] = -10;
	// board[32] = -2;
	// board[34] = -22;

	// for(int u=0;u<=36;u++){
	// 	for(int dice = 1; dice<=6;dice++){
	// 		int v = u+dice+board[u+dice];
	// 		g.addEdge(u,v,false);
	// 	}
	// }
	// cout<<g.SSSP(0,36)<<endl;
	// g.addEdge("Putin","Trump",false);
	// g.addEdge("Putin","Modi",false);
	// g.addEdge("Trump","Modi",true);
	// g.addEdge("Yogi","Modi",true);
	// g.addEdge("Yogi","Prabhu",false);
	// g.addEdge("Prabhu","Modi",false);
	// g.addEdge("Putin","Pope",false);
	// g.Print();

	return 0;
}