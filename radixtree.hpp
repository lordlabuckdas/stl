// reached end of lesson to realize that radix tree is same as trie
// so, modify trie w/ alphabet size etc to accomodate this
#include <iostream>
#include <string>

namespace stl {
	class radixnode {
		public:
			bool is_end;
			radixnode *left, *right;
			radixnode(): is_end(false), left(NULL), right(NULL) {}
	};

	class radixtree {
		protected:
			radixnode *root;
		public:
			radixtree(): root(new radixnode()) {}
			void insert(std::string);
			void print();
			void print_rec(radixnode*, std::string);
	};

	void radixtree::insert(std::string key) {
		radixnode *curr = root;
		int key_length = key.length();
		for(int i=0;i<key_length;i++) {
			if(key[i] == '0') {
				if(!curr->left)
					curr->left = new radixnode();
				curr = curr->left;
			} else {
				if(!curr->right)
					curr->right = new radixnode();
				curr = curr->right;
			}
		}
		curr->is_end = true;
	}

	void radixtree::print() {
		radixnode *ptr = root;
		std::string bit_string;
		print_rec(ptr, bit_string);
	}

	void radixtree::print_rec(radixnode *ptr, std::string bit_string) {
		if(!ptr) {
			return;
		}
		if(ptr->is_end) {
			std::cout<<bit_string<<" ";
		}
		print_rec(ptr->left, bit_string + "0");
		print_rec(ptr->right, bit_string + "1");
	}
}
