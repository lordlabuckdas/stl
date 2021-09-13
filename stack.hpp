#include <stdexcept>
#include <iostream>

namespace stl {
  template<typename T>
  class stack {
    unsigned int _size, capacity;
    unsigned int MAX_CAPACITY = 1e5;
    T *st;
    unsigned int _min(unsigned int, unsigned int);
    public:
    stack();
    stack(unsigned int);
    unsigned int size();
    void resize(unsigned int);
    T top();
    T pop();
    void insert(T);
  };

  template<typename T>
  stack<T>::stack() {
    this->_size = 0;
    this->capacity = 10;
    this->st = new T[10];
  }

  template<typename T>
  stack<T>::stack(unsigned int cap) {
    this->_size = 0;
    this->capacity = cap;
    this->st = new T[cap];
  }

  template<typename T>
  unsigned int stack<T>::_min(const unsigned int a, const unsigned int b) {
    return a<b?a:b;
  }

  template<typename T>
  unsigned int stack<T>::size() {
    return this->_size;
  }

  template<typename T>
  void stack<T>::resize(unsigned int new_cap) {
    T *temp = new T[new_cap];
    for(unsigned int i = 0; i < this->_size; i++)
      temp[i] = this->st[i];
    delete []this->st;
    this->st = temp;
  }

  template<typename T>
  T stack<T>::top() {
    if(!this->_size)
      throw std::underflow_error("Stack is empty!");
    return this->st[this->_size - 1];
  }

  template<typename T>
  T stack<T>::pop() {
    if(!this->_size)
      throw std::underflow_error("Stack is empty");
    this->_size--;
    return *(this->st + this->_size);
  }

  template<typename T>
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
