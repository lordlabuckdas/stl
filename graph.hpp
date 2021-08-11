#include<iostream>
// TODO: replace with custom list
#include<list>

namespace stl {
  class graph {
    int V;
    std::list<int> *adj;
    /* int *components; */
    /* int num_components; */
    public:
    graph(int);
    ~graph();
    int size();
    void add_edge(int, int);
    void dfs();
    void _dfs(int, bool[]);
    /* void bfs(); */
    /* int find_components(); */
    /* void _components(); */
  }

  graph::graph(int vertices) {
    this->V = vertices;
    this->adj = new std::list<int> [V];
  }

  graph::~graph() {
    delete[] adj;
  }

  int graph::size() {
    return V;
  }

  void graph::add_edge(int u, int v) {
    this->adj[u].push(v);
    this->adj[v].push(u);
  }

  void graph::add_edges(int u, int v[])

  void graph::dfs() {
    bool visited[this->V] = {0};
    for(int i=0; i<this->V;i++)
      _dfs(i, visited);
  }

  void graph::_dfs(int u, bool visited[]) {
    visited[u] = 1;
    for(int i=0;i<(int)adj[u].size();i++)
      if(!visited[adj[u][i]])
        _dfs(adj[u][i], visited);
  }

  /* int graph::find_components() { */
  /*   std::cout<<"Not implemented yet!"; */
  /* } */
}
