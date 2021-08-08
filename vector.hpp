#include <iostream>

namespace stl {
	template <typename T> class vector {
		T *data;
		int vsize, cap;
		public:
		vector();
		vector(int);
		vector(int, T);
		int size();
		bool is_empty();
	};

	template <typename T> vector<T>::vector() {
		data = NULL;
		vsize = 0;
		cap = 10;
	}

	template <typename T> vector<T>::vector(int n) {
		data = new T[n];
		vsize = 0;
		cap = n;
	}

	template <typename T> vector<T>::vector(int n, T v) {
		data = new T[n];
		for(auto it: data)
			it=v;
		vsize = n;
		cap = n;
	}

	template <typename T> int vector<T>::size() {
		return vsize;
	}

	template <typename T> bool vector<T>::is_empty() {
		return vsize==0;
	}
}
