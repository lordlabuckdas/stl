#include<iostream>
// TODO: replace with custom map
#include<map>

class graph {
  int V;
  vector<bool> visited;
  vector<vector<int>> adj;
public:
  graph();
  graph(int);
  ~graph();
}

graph::graph() {
  V = 0;
}

graph::graph(int vertices) {
  V = vertices;
  visited = new vector<bool> (V, false);
  adj = new vector<vector<int>> (V);
}

graph::~graph() {
  if(!V)
    return;
  delete[] visited;
  for(int i=0;i<adj.size();i++) {
    delete[] adj[i];
  }
  delete[] adj;
}
