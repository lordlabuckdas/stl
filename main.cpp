#include "bst.h"
using namespace std;

int main() {
	stl::bst<int> a;
	a.insert(20);
	a.insert(10);
	a.insert(30);
	a.inorder_rec();
	return 0;
}
