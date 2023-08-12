#pragma once
#include <vector>

using namespace std;

class Adapter {

};

class Graph {
	int V; // Number of vertices
	vector<vector<int>> adj; // Adjacency list

public:
	Graph(int v) : V(v), adj(v) {}
	
	int getV() { return V; }

	vector<vector<int>> getAdj() { return adj; }

	void addEdge(int u, int v) {
		adj[u].push_back(v);
	}

};