#pragma once
#include <iostream>
#include <vector>
#include <queue>

#include "Adapter.h"
#include "Algorithm.h"

using namespace std;

class BFS : public Algorithm {

public:
    
    void execute(Searchable* g, int s) override {
        vector<vector<int>> adj = g->getAdj();
        
        vector<bool> visited(g->getV(), false); // Keep track of visited vertices        
        queue<int> q;

        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};