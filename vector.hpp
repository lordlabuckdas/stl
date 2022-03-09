#include <stdexcept>

namespace stl {
    template <typename T>
    class vector {
    private:
        T* ptr;
        size_t _size, cap;
        const size_t MAX_CAP = 1e5;
    public:
        vector();
        vector(size_t);
        vector(size_t, T);
        vector(T*, T*);
        ~vector();
        size_t size();
        bool is_empty();
        static T _min(T, T);
        T* begin();
        T* end();
        T* resize(size_t);
        void push_back(T);
        T& operator[](int);
    };

    template <typename T>
    vector<T>::vector() {
        this->ptr = nullptr;
        this->_size = 0;
        this->cap = 2;
    }

    template <typename T>
    vector<T>::vector(size_t n) {
        this->ptr = new T[n];
        this->_size = 0;
        this->cap = n;
    }

    template <typename T>
    vector<T>::vector(size_t n, T val) {
        this->ptr = new T[n];
        for(int i = 0; i < n; ++i) {
            ptr[i] = val;
        }
        this->_size = n;
        this->cap = n;
    }

    template <typename T>
    vector<T>::vector(T* beg, T* end) {
        this->_size = 0;
        for(T* i = beg; i != end; ++i, ++this->_size) {
            this->push_back(*i);
        }
        this->cap = this->_size;
    }

    template <typename T>
    vector<T>::~vector() {
        delete[] this->ptr;
    }

    template <typename T>
    size_t vector<T>::size() {
        return this->_size;
    }

    template <typename T>
    bool vector<T>::is_empty() {
        return !this->_size;
    }

    template <typename T>
    T vector<T>::_min(T a, T b) {
        return (a < b) ? a : b;
    }

    template <typename T>
    T* vector<T>::begin() {
        return this->ptr;
    }

    template <typename T>
    T* vector<T>::end() {
        return this->ptr + this->_size;
    }

    template <typename T>
    T* vector<T>::resize(size_t new_cap) {
        T* new_ptr = new T[new_cap];
        this->_size = this->_min(this->_size, new_cap);
        for(int i = 0; i < this->_size; ++i) {
            new_ptr[i] = ptr[i];
        }
        delete[] this->ptr;
        this->_ptr = new_ptr;
        this->cap = new_cap;
        return this->ptr + this->_size - 1;
    }

    template <typename T>
    void vector<T>::push_back(T val) {
        if(this->_size == this->cap) {
            int new_cap = this->_min(2 * this->cap, MAX_CAP);
            this->resize(new_cap);
        }
        ptr[this->_size++] = val;
    }

    template <typename T>
    T& vector<T>::operator[](int idx) {
        if(idx < 0) {
            throw std::out_of_range("Negative index\n");
        }
        if(idx >= this->_size) {
            throw std::out_of_range("Index greater than size of vector\n");
        }
        return ptr[idx];
    }
}
