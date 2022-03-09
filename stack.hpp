#include <stdexcept>

namespace stl {
    template <typename T>
    class stack {
    private:
        size_t _size, cap;
        size_t MAX_CAPACITY = 1e5;
        T *st;
        size_t _min(size_t, size_t);
    public:
        stack(size_t = 10);
        ~stack();
        size_t size();
        void resize(size_t);
        T top();
        T pop();
        void insert(T);
    };

    template <typename T>
    stack<T>::stack(size_t cap) {
        this->_size = 0;
        this->capacity = cap;
        this->st = new T[cap];
    }

    template <typename T>
    stack<T>::~stack() {
        delete[] this->st;
    }

    template <typename T>
    size_t stack<T>::_min(const size_t a, const size_t b) {
        return a<b?a:b;
    }

    template <typename T>
    size_t stack<T>::size() {
        return this->_size;
    }

    template <typename T>
    void stack<T>::resize(size_t new_cap) {
        T *temp = new T[new_cap];
        for(size_t i = 0; i < this->_size; i++)
            temp[i] = this->st[i];
        delete []this->st;
        this->st = temp;
    }

    template <typename T>
    T stack<T>::top() {
        if(!this->_size)
            throw std::underflow_error("Stack is empty!");
        return this->st[this->_size - 1];
    }

    template <typename T>
    T stack<T>::pop() {
        if(!this->_size)
            throw std::underflow_error("Stack is empty");
        this->_size--;
        return *(this->st + this->_size);
    }

    template <typename T>
    void stack<T>::insert(T item) {
        if(this->_size >= this->capacity) {
            if(this->capacity == this->MAX_CAPACITY)
                throw std::overflow_error("Reached max capacity, cannot resize!");
            resize(_min(2*this->capacity, this->MAX_CAPACITY));
        }
        this->st[this->_size] = item;
        this->_size++;
    }
}
