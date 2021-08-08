#include <iostream>
#include "tree.h"

namespace stl {
	template <typename T> class bst : public tree<T> {
		public:
			bst(): tree<T>() {}
			bst(T x): tree<T>(x) {}
			void insert(T);
			treenode<T>* insert_rec(treenode<T>*, T);
			void remove(T);
			void remove_rec(T);
			treenode<T>* remove_rec(treenode<T>*, T);
			bool search(T);
			treenode<T>* min();
			treenode<T>* min_rec();
			treenode<T>* min_rec(treenode<T>*);
			treenode<T>* max();
			treenode<T>* max_rec();
			treenode<T>* max_rec(treenode<T>*);
	};

	template <typename T> void bst<T>::insert(T x) {
		treenode<T> *node = new treenode<T>(x);
		if(this->empty()) {
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

	template <typename T> void bst<T>::remove(T k) {
		if(this->empty()) {
			std::cout<<"Empty tree!\n";
			return;
		}
		treenode<T> *ptr = this->root, *par = NULL;
		while(ptr && ptr->val!=k) {
			par = ptr;
			if(k > ptr->val)
				ptr = ptr->right;
			else
				ptr = ptr->left;
		}
		if(!ptr) {
			std::cout<<"Node not found!\n";
			return;
		}
		if(!ptr->right) {
			treenode<T> *temp = ptr;
			if(par->left==ptr)
				par->left = ptr->left;
			else
				par->right = ptr->left;
			ptr = ptr->left;
			delete temp;
		} else if(!ptr->left) {
			treenode<T> *temp = ptr;
			if(par->left==ptr)
				par->left = ptr->right;
			else
				par->right = ptr->right;
			ptr = ptr->right;
			delete temp;
		} else {
			treenode<T> *successor_parent = ptr, *successor = ptr->right;
			while(successor->left) {
				successor_parent = successor;
				successor = successor->left;
			}
			if(successor_parent!=ptr)
				successor_parent->left = successor->right;
			else
				successor_parent->right = successor->right;
			ptr->val = successor->val;
			delete successor;
		}
	}

	template <typename T> void bst<T>::remove_rec(T k) {
		this->root = remove_rec(this->root, k);
	}

	template <typename T> treenode<T>* bst<T>::remove_rec(treenode<T> *ptr, T k) {
		if(!ptr)
			return ptr;
		if(k > ptr->val) {
			ptr->right = remove_rec(ptr->right, k);
			return ptr;
		}
		if(k < ptr->val) {
			ptr->left = remove_rec(ptr->left, k);
			return ptr;
		}
		if(!ptr->right) {
			treenode<T> *temp = ptr->left;
			delete ptr;
			return temp;
		} else if(!ptr->left) {
			treenode<T> *temp = ptr->right;
			delete ptr;
			return temp;
		} else {
			treenode<T> *successor_parent = ptr, *successor = ptr->right;
			while(successor->left) {
				successor_parent = successor;
				successor = successor->left;
			}
			if(successor_parent!=ptr)
				successor_parent->left = successor->right;
			else
				successor_parent->right = successor->right;
			ptr->val = successor->val;
			delete successor;
			return ptr;
		}
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

	// template <typename T> treenode<T>* find_successor(treenode<T> *ptr) {
	// 	if(ptr->right)
	// 		return find_min(ptr->right);
	// 	treenode<T> *par = ptr->parent;
	// 	while(par && par->right==ptr) {
	// 		ptr = par;
	// 		par = par->parent;
	// 	}
	// 	return par;
	// }

	// template <typename T> treenode<T>* find_predecessor(treenode<T> *ptr) {
	// 	if(ptr->left)
	// 		return find_max(ptr->left);
	// 	treenode<T> *par = ptr->parent;
	// 	while(par && par->left==ptr) {
	// 		ptr = par;
	// 		par = par->parent;
	// 	}
	// 	return par;
	// }
}
