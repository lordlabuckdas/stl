namespace stl {
  class queue {
    int *_front, *_rear;
    unsigned int size, capacity;
    public:
    queue(unsigned int);
    queue();
    unsigned int size();
    int front();
    int rear();
  }

  queue::queue(unsigned int cap) {
    this->size = 0;
    this->capacity = cap;
  }

  queue::queue() {
    queue(10);
  }

  int queue::front() {
    return *this->_front;
  }

  int queue::rear() {
    return *this->_rear;
  }

  unsigned int queue::size() {
    return this->size;
  }
}
