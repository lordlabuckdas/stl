namespace stl {
  class string {
    char *str;
    unsigned int _size, capacity;
    unsigned int MAX_CAPACITY = 1e5;
    public:
    string();
    string(char);
    string(char*);
    unsigned int size();
    char pop_back();
    void push_back(char);
  }
}
