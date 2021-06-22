#include<iostream>

namespace stl {
	template <typename T> class treenode {
		public:
		T val;
		treenode *left, *right, *parent;
		treenode(T);
		treenode(T, treenode<T>*);
	};

	template <typename T> treenode<T>::treenode(T x): val(x), left(NULL), right(NULL), parent(NULL) {};

	template <typename T> treenode<T>::treenode(T x, treenode<T> *p): val(x), left(NULL), right(NULL), parent(p) {};

	template <typename T> class tree {
		protected:
		treenode<T> *root;
		public:
		tree();
		tree(T);
		void inorder();
		void inorder_rec();
		void inorder_rec(treenode<T>*);
		void preorder();
		void preorder_rec();
		void preorder_rec(treenode<T>*);
		void postorder();
		void postorder_rec();
		void postorder_rec(treenode<T>*);
	};

	template <typename T> tree<T>::tree(): root(NULL) {}

	template <typename T> tree<T>::tree(T x): root(new treenode(x)) {}

	template <typename T> void tree<T>::inorder() {
		std::cout<<"Not implemented yet!";
	}

	template <typename T> void tree<T>::inorder_rec() {
		inorder_rec(root);
	}

	template <typename T> void tree<T>::inorder_rec(treenode<T> *ptr) {
		if(ptr) {
			inorder_rec(ptr->left);
			std::cout<<ptr->val<<' ';
			inorder_rec(ptr->right);
		}
	}

	template <typename T> void tree<T>::preorder() {
		std::cout<<"Not implemented yet!";
	}

	template <typename T> void tree<T>::preorder_rec() {
		preorder_rec(root);
	}

	template <typename T> void tree<T>::preorder_rec(treenode<T> *ptr) {
		if(ptr) {
			std::cout<<ptr->val<<' ';
			preorder_rec(ptr->left);
			preorder_rec(ptr->right);
		}
	}

	template <typename T> void tree<T>::postorder() {
		std::cout<<"Not implemented yet!";
	}

	template <typename T> void tree<T>::postorder_rec() {
		postorder_rec(root);
	}

	template <typename T> void tree<T>::postorder_rec(treenode<T> *ptr) {
		if(ptr) {
			postorder_rec(ptr->left);
			postorder_rec(ptr->right);
			std::cout<<ptr->val<<' ';
		}
	}

}
