#include "trie.hpp"
#include "radixtree.hpp"
#include "sparse_table.hpp"
#include <vector>
#include <string>
#include "lru_cache.hpp"
using namespace std;

int main() {
  // stl::bst<int> a;
  // a.insert(20);
  // a.insert(10);
  // a.insert(30);
  // a.insert(25);
  // a.insert(40);
  // cout<<a.get_root()->val;
  // cout<<'\n';
  // a.inorder_rec();
  // cout<<'\n';
  // a.delete_node(20);
  // a.inorder_rec();
  // cout<<'\n';
  // cout<<a.get_root()->val;
  // stl::trie a;
  // a.insert("hello");
  // a.insert("hell");
  // a.insert("lmao");
  // a.insert("hel");
  // cout<<a.search("hello");
  // cout<<'\n';
  // cout<<a.search("hell");
  // cout<<'\n';
  // cout<<a.search("ohho");
  // cout<<'\n';
  // a.print();
  // a.remove("hell");
  // cout<<a.search("hell");
  // cout<<'\n';
  // cout<<a.search("hello");
  // cout<<'\n';
  // a.print();
  // vector<string> matches = a.find_all("he");
  // for(auto i: matches)
  // 	cout<<i<<" ";
  /* stl::radixtree rt; */
  /* rt.insert("0"); */
  /* rt.insert("011"); */
  /* rt.insert("10"); */
  /* rt.insert("100"); */
  /* rt.insert("1011"); */
  /* rt.print(); */
  /* vector<int> val = {76,4,36,21,51,32,15,43,66}; */
  /* stl::min_sparse_table st(val); */
  /* cout<<st.query(2,5); */
  stl::lru_cache<int, int> cache(2);
  cache.put(2,20);
  cout<<"2: "<<cache.get(2)<<'\n';
  cout<<"1: "<<cache.get(1)<<'\n';
  cache.put(1,10);
  cout<<"1: "<<cache.get(1)<<'\n';
  cache.put(1,100);
  cout<<"1: "<<cache.get(1)<<'\n';
  cache.put(8,88);
  cout<<"1: "<<cache.get(1)<<'\n';
  cout<<"8: "<<cache.get(8)<<'\n';
  cout<<"2: "<<cache.get(2)<<'\n';
  return 0;
}
