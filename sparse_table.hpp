#include<iostream>
#include<climits>
// TODO: use custom vector
#include<vector>

namespace stl {
  class min_sparse_table {
    int N, P;
    int *log2;
    int **lookup;
    int **idx;
  public:
    min_sparse_table(std::vector<int>);
    int query(int, int);
    int cascading_query(int, int);
    int query_index(int, int);
    ~min_sparse_table();
  };
  
  min_sparse_table::min_sparse_table(std::vector<int> values) {
    this->N = values.size();
    this->log2 = new int[this->N+1];
    log2[0] = log2[1] = 0;
    for(int i=2;i<=this->N;i++)
      log2[i] = log2[i/2] + 1;
    this->P = log2[this->N];
    this->lookup = new int*[this->P+1];
    this->idx = new int*[this->P+1];
    for(int i=0;i<=this->P;i++) {
      lookup[i] = new int[this->N];
      idx[i] = new int[this->N];
    }
    for(int i=0;i<this->N;i++) {
      lookup[0][i] = values[i];
      idx[0][i] = i;
    }
    for(int i=1;i<=this->P;i++) {
      for(int j=0;j+(1<<i)<=this->N;j++) {
        int left = lookup[i-1][j];
        int right = lookup[i-1][j+(1<<(i-1))];
        lookup[i][j] = std::min(left, right);
        if(left<=right)
          idx[i][j] = idx[i-1][j];
        else
          idx[i][j] = idx[i-1][j+(1<<(i-1))];
      }
    }
  }

  int min_sparse_table::query(int l, int r) {
    int len = r-l+1;
    int p = this->log2[len];
    int left = lookup[p][l];
    int right = lookup[p][r-(1<<p)+1];
    return std::min(left, right);
  }

  int min_sparse_table::cascading_query(int l, int r) {
    int min_val = INT_MAX;
    for(int p=log2[r-l+1];l<=r;p=log2[r-l+1]) {
      min_val = std::min(min_val, lookup[p][l]);
      l += (1<<p);
    }
    return min_val;
  }

  int min_sparse_table::query_index(int l, int r) {
    int len = r-l+1;
    int p = this->log2[len];
    int left = lookup[p][l];
    int right = lookup[p][r-(1<<p)+1];
    if(left<=right)
      return idx[p][l];
    return idx[p][r-(1<<p)+1];
  }

  min_sparse_table::~min_sparse_table() {
    delete[] this->log2;
    for(int i=0;i<=this->P;i++) {
      delete[] this->lookup[i];
      delete[] this->idx[i];
    }
    delete[] this->lookup;
    delete[] this->idx;
  }
}
