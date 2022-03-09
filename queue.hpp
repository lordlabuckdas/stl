// #include <cstddef>
#include <stdexcept>

namespace stl {
    template <typename T>
    class queue {
    private:
        T* ptr;
        size_t _size, cap;
        // T* resize(size_t);
    public:
        queue(size_t = 10);
        ~queue();
        size_t size();
        T front();
        T rear();
        void push(T);
        T pop();
    };

    template <typename T>
    queue<T>::queue(size_t c) {
        this->_size = 0;
        this->cap = c;
        this->ptr = new T[c];
    }

    template <typename T>
    queue<T>::~queue() {
        delete[] ptr;
    }

    template <typename T>
    T queue<T>::front() {
        return this->ptr;
    }

    template <typename T>
    T queue<T>::rear() {
        return this->ptr + this->_size - 1;
    }

    template <typename T>
    size_t queue<T>::size() {
        return this->_size;
    }

    template <typename T>
    void queue<T>::push(T val) {
        if(this->_size == this->cap) {
            throw std::out_of_range("Queue has reached its max size\n");
            // if(this->is_fixed_size) {
            //     throw std::out_of_range("Queue has reached its max size\n");
            // }
            // resize
        }
        this->ptr[this->_size++] = val;
    }

    template <typename T>
    T queue<T>::pop() {
        if(this->_size == 0) {
            throw std::out_of_range("No elements left to pop in queue\n");
        }
        return this->ptr[--this->_size];
    }
}
