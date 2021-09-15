#include <cstddef>

namespace stl {
  class list_node {
    public:
    int val;
    list_node *next;
    list_node();
    list_node(int);
  };

  list_node::list_node() {
    this->val = 0;
    this->next = NULL;
  }

  list_node::list_node(int v) {
    this->val = v;
    this->next = NULL;
  }

  class list {
    public:
    list_node *head;
    list();
    list(int);
    void insert(int);
    void print();
  }
}
