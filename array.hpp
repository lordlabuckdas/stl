#include <stdexcept>

namespace stl {
  template<typename T>
  class array {
    unsigned int size, capacity;
    T *ptr;
    public:
    array(unsigned int);
    array();
    ~array();
    T* begin();
    T* end();
    T& operator[](int);
  };

  template<typename T>
  array<T>::array(unsigned int cap) {
    this->size = 0;
    this->capacity = cap;
    this->ptr = new T[cap];
  }

  template<typename T>
  array<T>::array() {
    array(10);
  }

  template<typename T>
  array<T>::~array() {
    delete []this->ptr;
  }

  template<typename T>
  T* array<T>::begin() {
    return this->ptr;
  }

  template<typename T>
  T* array<T>::end() {
    return (this->ptr + this->size);
  }

  template<typename T>
  T& array<T>::operator[](int index) {
    if(index >= (int)this->capacity)
      throw std::out_of_range("Index greater than capacity!");
    return *(this->ptr + index);
  }
}
