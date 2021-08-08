#include <iostream>
#include <string>
#include <vector>

namespace stl {
	class trienode {
		public:
			trienode* children[26];
			bool is_leaf;
			trienode();
			bool is_empty();
	};

	trienode::trienode() {
		is_leaf = false;
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
	}

	bool trienode::is_empty() {
		for(int i=0;i<26;i++)
			if(children[i])
				return false;
		return true;
	}

	class trie {
		protected:
			trienode *root;
		public:
			trie();
			bool is_empty();
			void insert(std::string);
			bool search(std::string);
			void remove(std::string);
			trienode* remove_rec(trienode*, std::string, int);
			void print();
			void print_rec(trienode*, std::string);
			std::vector<std::string> find_all(std::string);
			void find_all_rec(trienode*, std::string, std::vector<std::string>&);
	};

	trie::trie(): root(new trienode()) {}

	bool trie::is_empty() {
		for(int i=0;i<26;i++)
			if(root->children[i])
				return false;
		return true;
	}

	void trie::insert(std::string key) {
		trienode *ptr = root;
		for(int i=0; i<(int)key.length(); i++) {
			int idx = key[i]-'a';
			if(!ptr->children[idx])
				ptr->children[idx] = new trienode();
			ptr = ptr->children[idx];
		}
		ptr->is_leaf = true;
	}

	bool trie::search(std::string key) {
		trienode *ptr = root;
		for(int i=0;i<(int)key.length();i++) {
			int idx = key[i]-'a';
			if(!ptr->children[idx])
				return false;
			ptr = ptr->children[idx];
		}
		return ptr->is_leaf;
	}

	void trie::remove(std::string key) {
		trienode* ptr = root;
		remove_rec(ptr, key, 0);
	}

	trienode* trie::remove_rec(trienode* ptr, std::string key, int depth) {
		if(!ptr)
			return NULL;
		if(depth == (int)key.length()) {
			if(ptr->is_leaf)
				ptr->is_leaf = false;
			if(is_empty()) {
				delete ptr;
				ptr = NULL;
			}
			return ptr;
		}
		int idx = key[depth] - 'a';
		ptr->children[idx] = remove_rec(ptr->children[idx], key, depth+1);
		return ptr;
	}

	void trie::print() {
		std::string word;
		trienode *ptr = root;
		print_rec(ptr, word);
	}

	void trie::print_rec(trienode *ptr, std::string word) {
		if(ptr->is_leaf) {
			std::cout<<word<<' ';
		}
		for(int i=0;i<26;i++)
			if(ptr->children[i]) {
				word += i + 'a';
				print_rec(ptr->children[i], word);
				word.pop_back();
			}
	}

	std::vector<std::string> trie::find_all(std::string query) {
		std::vector<std::string> res;
		trienode *ptr = root;
		for(int i=0;i<(int)query.length();i++) {
			int idx = query[i] - 'a';
			if(!ptr->children[idx])
				return res;
			ptr = ptr->children[idx];
		}
		bool has_children = !ptr->is_empty();
		if(ptr->is_leaf && !has_children) {
			res.push_back(query);
			return res;
		}
		if(has_children) {
			find_all_rec(ptr, query, res);
		}
		return res;
	}

	void trie::find_all_rec(trienode *ptr, std::string word, std::vector<std::string> &res) {
		if(ptr->is_leaf) {
			res.push_back(word);
		}
		if(ptr->is_empty()) {
			return;
		}
		for(int i=0;i<26;i++) {
			if(ptr->children[i]) {
				word += i + 'a';
				find_all_rec(ptr->children[i], word, res);
				word.pop_back();
			}
		}
	}
}
