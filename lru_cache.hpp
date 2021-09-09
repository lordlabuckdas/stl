#include<cstddef>
#include<unordered_map>

namespace stl {
  template<typename K, typename V>
  class dll_node {
    public:
    K key;
    V val;
    dll_node *prev, *next;
    dll_node(K, V);
  };

  template<typename K, typename V>
  dll_node<K, V>::dll_node(K k, V v) {
    this->key = k;
    this->val = v;
    prev = NULL;
    next = NULL;
  }

  template<typename K, typename V>
  class dll {
    dll_node<K, V> *front, *rear;
    public:
    dll();
    bool is_empty();
    dll_node<K, V>* get_rear();
    dll_node<K, V>* insert(K, V);
    void reorder(dll_node<K, V>*);
    void remove();
  };

  template<typename K, typename V>
  dll<K, V>::dll() {
    this->front = this->rear = NULL;
  }

  template<typename K, typename V>
  bool dll<K, V>::is_empty() {
    return this->rear == NULL;
  }

  template<typename K, typename V>
  dll_node<K, V>* dll<K, V>::get_rear() {
    return this->rear;
  }

  template<typename K, typename V>
  dll_node<K, V>* dll<K, V>::insert(K k, V v) {
    dll_node<K, V> *node = new dll_node<K, V>(k, v);
    if(this->is_empty()) {
      this->front = this->rear = node;
    } else {
      node->next = this->front;
      this->front->prev = node;
      this->front = node;
    }
    return node;
  }
  
  template<typename K, typename V>
  void dll<K, V>::reorder(dll_node<K, V> *node) {
    if(this->front == node)
      return;
    if(this->rear == node) {
      this->rear = this->rear->prev;
      this->rear->next = NULL;
    } else {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }
    node->next = this->front;
    node->prev = NULL;
    this->front->prev = node;
    this->front = node;
  }

  template<typename K, typename V>
  void dll<K, V>::remove() {
    if(is_empty())
      return;
    if(this->front == this->rear) {
      delete this->front;
      this->front = this->rear = NULL;
    } else {
      dll_node<K, V> *temp = this->rear;
      this->rear = this->rear->prev;
      this->rear->next = NULL;
      delete temp;
    }
  }

  template<typename K, typename V>
  class lru_cache {
    unsigned int size, capacity;
    std::unordered_map<K, dll_node<K, V>*> cache;
    dll<K, V> *usage_list;
    public:
    lru_cache(int);
    lru_cache();
    ~lru_cache();
    void put(K, V);
    V get(K);
  };

  template<typename K, typename V>
  lru_cache<K, V>::lru_cache(int cap) {
    this->capacity = cap;
    this->size = 0;
    this->cache = std::unordered_map<K, dll_node<K, V>*>();
    this->usage_list = new dll<K, V>();
  }

  template<typename K, typename V>
  lru_cache<K, V>::lru_cache() {
    lru_cache(10);
  }

  template<typename K, typename V>
  lru_cache<K, V>::~lru_cache() {
    for(auto &it: this->cache)
      delete it.second;
    delete this->usage_list;
  }

  template<typename K, typename V>
  void lru_cache<K, V>::put(K k, V v) {
    if(this->cache.find(k)!=this->cache.end()) {
      this->cache[k]->val = v;
      this->usage_list->reorder(this->cache[k]);
      return;
    }
    if(this->size == this->capacity) {
      K rear_key = this->usage_list->get_rear()->key;
      this->cache.erase(rear_key);
      this->usage_list->remove();
      this->size--;
    }
    dll_node<K, V> *new_node = this->usage_list->insert(k, v);
    this->size++;
    this->cache[k] = new_node;
  }

  template<typename K, typename V>
  V lru_cache<K, V>::get(K k) {
    if(this->cache.find(k) == this->cache.end()) {
      return -1;
    }
    this->usage_list->reorder(this->cache[k]);
    return this->cache[k]->val;
  }
}
