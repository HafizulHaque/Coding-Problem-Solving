#include <bits/stdc++.h>
using namespace std;

#define N 15     // Number of vertex
struct Edge {
	int src, dest;
};

class Graph{
public:
	vector<int> adjList[N];     // adjacency list

	Graph(vector<Edge> edges){  // Constructor
		// add edges to the undirected graph
		for (int i = 0; i < edges.size(); i++){
			int src = edges[i].src;
			int dest = edges[i].dest;

			adjList[src].push_back(dest);
			adjList[dest].push_back(src);
		}
	}
};

// Perform BFS recursively on graph
void recursiveBFS(Graph const &graph, queue<int> &q, vector<bool> &discovered){
	if (q.empty())
		return;

	// pop front node from queue and print it
	int v = q.front();
	q.pop();
	cout << v << " ";

	// do for every edge (v -> u)
	for (int u : graph.adjList[v]){
		if (!discovered[u]){
			// mark it discovered and push it into queue
			discovered[u] = true;
			q.push(u);
		}
	}
	recursiveBFS(graph, q, discovered);
}

// Recursive C++ implementation of Breadth first search
int main(){
	vector<Edge> edges = {
		{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
		{5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
	};

	Graph graph(edges);
	vector<bool> discovered(N);
	queue<int> q;

	// Do BFS traversal from all undiscovered nodes to
	// cover all unconnected components of graph
	for (int i = 0; i < N; i++) {
		if (discovered[i] == false){
			discovered[i] = true;
			q.push(i);

			// start BFS traversal from vertex i
			recursiveBFS(graph, q, discovered);
		}
	}
	return 0;
}
