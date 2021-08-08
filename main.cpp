#include "trie.hpp"
#include "radixtree.hpp"
#include <vector>
#include <string>
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
	stl::radixtree rt;
	rt.insert("0");
	rt.insert("011");
	rt.insert("10");
	rt.insert("100");
	rt.insert("1011");
	rt.print();
	return 0;
}
