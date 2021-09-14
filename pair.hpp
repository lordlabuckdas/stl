namespace stl {
  template<typename T1, typename T2>
  class pair {
    public:
    T1 first;
    T2 second;
    pair(T1, T2);
  }

  pair::pair(T1 f, T2 s) {
    this->first = f;
    this->second = s;
  }
}
