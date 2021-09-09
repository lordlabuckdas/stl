#include <unordered_map>
#include <pair>

namespace stl {
  template <typename K, typename V>
  class ttl_cache {
    std::unordered_map<K, std::pair<V, unsigned int>> cache;
    int get_current_time();
    public:
    ttl_cache();
    void put(K, V, int);
    V get(K);
  };

  template <typename K, typename V>
  ttl_cache<K, V>::ttl_cache() {
    this->cache = std::unordered_map<K, std::pair<V, unsigned int>>();
  }

  template <typename K, typename V>
  int ttl_cache<K, V>::get_current_time() {
    return 100;
  }

  template <typename K, typename V>
  void ttl_cache<K, V>::put(K k, V v, int ttl) {
    int expiry_time = this->get_current_time() + ttl;
    this->cache[k] = {v, expiry_time};
  }

  template <typename K, typename V>
  V ttl_cache<K, V>::get(K k) {
    int curr_time = this->get_current_time();
    if(this->cache.find(k) == this.cache.end())
      return -1;
    std::pair<V, int> val = this->cache[k];
    if(val.second > curr_time)
      return val.first;
    this->cache.erase(k);
    return -1;
  }
}
