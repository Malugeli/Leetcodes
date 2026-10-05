class LRUCache {
public:
  LRUCache(int capacity) { cap = capacity; }

  int get(int key) {
    auto it = hash.find(key);
    if (it == hash.end()) return -1;

    // Als "zuletzt benutzt" nach vorne schieben
    lru.splice(lru.begin(), lru, it->second.first);
    return it->second.second;
  }

  void put(int key, int value) {
    auto it = hash.find(key);

    // Fall 1: Key existiert -> Value updaten, nach vorne schieben
    if (it != hash.end()) {
      it->second.second = value;
      lru.splice(lru.begin(), lru, it->second.first);
      return;
    }

    // Fall 2: neuer Key, Cache voll -> ältesten rauswerfen
    if (static_cast<int>(hash.size()) == cap) {
      hash.erase(lru.back());
      lru.pop_back();
    }

    // Neuen Key vorne einfügen
    lru.push_front(key);
    hash[key] = {lru.begin(), value};
  }

private:
  std::unordered_map<int, std::pair<std::list<int>::iterator, int>> hash;
  std::list<int> lru;
  int cap;
};