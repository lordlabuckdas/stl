#include <iostream>
#include "tree.h"

namespace stl {
	template <typename T> class bst : public tree<T> {
		public:
		bst(): tree<T>() {}
		bst(T x): tree<T>(x) {}
		bool is_empty();
		treenode<T>* get_root();
		void insert(T);
		treenode<T>* insert_rec(treenode<T>*, T);
		void delete_node(T);
		bool search(T);
		treenode<T>* min();
		treenode<T>* min_rec();
		treenode<T>* min_rec(treenode<T>*);
		treenode<T>* max();
		treenode<T>* max_rec();
		treenode<T>* max_rec(treenode<T>*);
	};

	template <typename T> bool bst<T>::is_empty() {
		if(this->root)
			return false;
		return true;
	}

	template <typename T> treenode<T>* bst<T>::get_root() {
		return this->root;
	}

	template <typename T> void bst<T>::insert(T x) {
		treenode<T> *node = new treenode<T>(x);
		if(is_empty()) {
			this->root = node;
			return;
		}
		treenode<T> *tmp = this->root, *prev = NULL;
		while(tmp) {
			prev = tmp;
			if(x > tmp->val)
				tmp = tmp->right;
			else
				tmp = tmp->left;
		}
		if(prev->val > x)
			prev->left = node;
		else
			prev->right = node;
	}

	template <typename T> treenode<T>* bst<T>::insert_rec(treenode<T> *ptr, T x) {
		if(!ptr)
			return new treenode<T>(x);
		if(x > ptr->val)
			ptr->right = insert_rec(ptr->right, x);
		else
			ptr->left = insert_rec(ptr->left, x);
		return ptr;
	}

	template <typename T> void bst<T>::delete_node(T x) {
		std::cout<<"Not implemented yet!";
	}

	template <typename T> bool bst<T>::search(T x) {
		treenode<T> *curr = this->root;
		while(curr) {
			if(x==curr->val)
				return true;
			else if(x<curr->val)
				curr = curr->left;
			else
				curr = curr->right;
		}
		return false;
	}

	template <typename T> treenode<T>* bst<T>::min() {
		treenode<T> *ptr = this->root;
		while(ptr->left)
			ptr = ptr->left;
		return ptr;
	}

	template <typename T> treenode<T>* bst<T>::min_rec() {
		return min_rec(this->root);
	}

	template <typename T> treenode<T>* bst<T>::min_rec(treenode<T> *ptr) {
		if(ptr->left)
			return min_rec(ptr->left);
		return ptr;
	}

	template <typename T> treenode<T>* bst<T>::max() {
		treenode<T> *ptr = this->root;
		while(ptr->right)
			ptr = ptr->right;
		return ptr;
	}

	template <typename T> treenode<T>* bst<T>::max_rec() {
		return max_rec(this->root);
	}

	template <typename T> treenode<T>* bst<T>::max_rec(treenode<T> *ptr) {
		if(ptr->right)
			return max_rec(ptr->right);
		return ptr;
	}

	template <typename T> treenode<T>* find_min(treenode<T> *ptr) {
		while(ptr->left)
			ptr = ptr->left;
		return ptr;
	}

	template <typename T> treenode<T>* find_min_rec(treenode<T> *ptr) {
		if(ptr->left)
			return find_min_rec(ptr->left);
		return ptr;
	}

	template <typename T> treenode<T>* find_max(treenode<T> *ptr) {
		while(ptr->right)
			ptr = ptr->right;
		return ptr;
	}

	template <typename T> treenode<T>* find_max_rec(treenode<T> *ptr) {
		if(ptr->right)
			return find_max_rec(ptr);
		return ptr;
	}

	template <typename T> treenode<T>* find_successor(treenode<T> *ptr) {
		if(ptr->right)
			return find_min(ptr->right);
		treenode<T> *par = ptr->parent;
		while(par && par->right==ptr) {
			ptr = par;
			par = par->parent;
		}
		return par;
	}

	template <typename T> treenode<T>* find_predecessor(treenode<T> *ptr) {
		if(ptr->left)
			return find_max(ptr->left);
		treenode<T> *par = ptr->parent;
		while(par && par->left==ptr) {
			ptr = par;
			par = par->parent;
		}
		return par;
	}
}
