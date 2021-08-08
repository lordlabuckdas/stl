#include <iostream>
// heh, bring your own stack
#include <stack>

namespace stl {
	template <typename T> class treenode {
		public:
			T val;
			treenode *left, *right;
			// treenode *parent;
			treenode(T);
			// treenode(T, treenode<T>*);
	};

	// template <typename T> treenode<T>::treenode(T x): val(x), left(NULL), right(NULL), parent(NULL) {};

	// template <typename T> treenode<T>::treenode(T x, treenode<T> *p): val(x), left(NULL), right(NULL), parent(p) {};
	
	template <typename T> treenode<T>::treenode(T x): val(x), left(NULL), right(NULL) {};

	template <typename T> class tree {
		protected:
			treenode<T> *root;
		public:
			tree();
			tree(T);
			bool empty();
			treenode<T>* get_root();
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

	template <typename T> bool tree<T>::empty() {
		if(root)
			return false;
		return true;
	}

	template <typename T> treenode<T>* tree<T>::get_root() {
		return this->root;
	}

	template <typename T> void tree<T>::inorder() {
		treenode<T> *curr = root;
		std::stack<treenode<T>*> st;
		while(curr!=NULL || !st.empty()) {
			if(curr!=NULL) {
				st.push(curr);
				curr = curr->left;
			} else {
				curr = st.top();
				st.pop();
				std::cout<<curr->val<<' ';
				curr = curr->right;
			}
		}
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
		treenode<T> *curr = root;
		std::stack<treenode<T>*> st;
		st.push(curr);
		while(!st.empty()) {
			curr = st.top();
			st.pop();
			std::cout<<curr->val<<' ';
			if(curr->right)
				st.push(curr->right);
			if(curr->left)
				st.push(curr->left);
		}
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
		treenode<T> *curr = root;
		std::stack<treenode<T>*> temp;
		std::stack<T> st;
		temp.push(curr);
		while(!temp.empty()) {
			curr = temp.top();
			temp.pop();
			st.push(curr->val);
			if(curr->left)
				temp.push(curr->left);
			if(curr->right)
				temp.push(curr->right);
		}
		while(!st.empty()) {
			std::cout<<st.top()<<' ';
			st.pop();
		}
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
