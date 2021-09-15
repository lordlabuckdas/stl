#include <cstddef>
#include "linked_list.hpp"

namespace stl {
  class dll_node: public list_node {
    public:
    dll_node *prev;
    dll_node();
    dll_node(int);
  };

  dll_node::dll_node(): list_node() {
    this->prev = NULL;
  }

  dll_node::dll_node(int v): list_node(v) {
    this->prev = NULL;
  }
}
