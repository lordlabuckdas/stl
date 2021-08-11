#include<iostream>
// TODO: use custom vector
#include<vector>
#include<math>

namespace stl {
  class min_sparse_table {
    int N, P;
    int **lookup;
  public:
    min_sparse_table(std::vector<int>);
    query(int, int);
  }
  
  min_sparse_table::min_sparse_table(std::vector<int> values) {
    this->N = values.size();
    this->P = log2(this->N);
    this->lookup = new int[this->N];
    for(int i=0;i<this->N;i++)
      lookup[i] = new int[this->P];
  }
}
