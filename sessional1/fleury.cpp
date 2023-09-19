#include<bits/stdc++.h>
using namespace std;

class Graph{
  int V;
	vector<list<int>> adj;

	bool isConnected();
	void dfsEuler(int v,vector<int>& path);
	void dfsUtil(int v,vector<bool>& visited);
public:
	Graph(int V);
	void addEdge(int u,int v);
	void removeEdge(int u,int v);
	void printEulerTour();
};

Graph::Graph(int V){
	this->V = V;
	adj = vector<list<int>>(V);
}

void Graph::addEdge(int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::removeEdge(int u,int v){
	adj[u].remove(v);
	adj[v].remove(u);
}

void Graph::dfsEuler(int v,vector<int>& path){
	path.push_back(v);
	for(auto it=adj[v].begin();it!=adj[v].end();it++){
		int u = *it;
		removeEdge(v,u);
		dfsEuler(u,path);
	}
}

bool Graph::isConnected(){
	vector<bool> visited(V,false);
	int i;
	for(i=0;i<V;i++){
		if(adj[i].size()>0)
			break;
	}
	if(i==V)
		return true;
	dfsUtil(i,visited);
	for(i=0;i<V;i++){
		if(visited[i]==false && adj[i].size()>0)
			return false;
	}
	return true;
}

void Graph::dfsUtil(int v,vector<bool>& visited){
	visited[v] = true;
	for(auto it=adj[v].begin();it!=adj[v].end();it++){
		if(visited[*it]==false)
			dfsUtil(*it,visited);
	}
}

void Graph::printEulerTour(){
	if(isConnected()==false){
		cout<<"Graph is not Eulerian\n";
		return;
	}
	int odd = 0;
	for(int i=0;i<V;i++){
		if(adj[i].size()&1)
			odd++;
	}
	if(odd>2){
		cout<<"Graph is not Eulerian\n";
		return;
	}
	vector<int> path;
	dfsEuler(0,path);
	for(int i=0;i<path.size();i++)
		cout<<path[i]<<" ";
	cout<<endl;
}

int main(){
	Graph g1(4);
	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 2);
	g1.addEdge(2, 3);
	g1.printEulerTour();

	Graph g2(3);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.addEdge(2, 0);
	g2.printEulerTour();

	Graph g3(5);
	g3.addEdge(1, 0);
	g3.addEdge(0, 2);
	g3.addEdge(2, 1);
	g3.addEdge(0, 3);
	g3.addEdge(3, 4);
	g3.addEdge(3, 2);
	g3.addEdge(3, 1);
	g3.addEdge(2, 4);
	g3.printEulerTour();

	return 0;
}
