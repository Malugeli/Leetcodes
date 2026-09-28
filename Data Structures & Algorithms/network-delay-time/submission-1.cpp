class Solution {
public:
  int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k) {
    std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
    for (auto t : times) {
      adj[t[0]].push_back({t[1], t[2]});
    }
    int inf = std::numeric_limits<int>::max();
    std::vector<int> dist(n + 1, inf);
    dist[k] = 0;

    using P = std::pair<int, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.push({0, k});

    int settled{};
    int answer{};

    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();

      if (d > dist[u]) {
        continue;
      }

      ++settled;
      answer = d;

      for (auto [v, w] : adj[u]) {
        if (d + w < dist[v]) {
          dist[v] = d + w;
          pq.push({dist[v], v});
        }
      }
    }
    return settled == n ? answer : -1;
  }
};
