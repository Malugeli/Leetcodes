class Solution {
public:
    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
        // Adjazenzliste: adj[u] enthält alle gerichteten Kanten u -> (v, w)
        std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
        for (const auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        std::vector<int> dist(n + 1, INT_MAX);  // bisher beste bekannte Ankunftszeit
        dist[k] = 0;

        // Min-Heap über (Distanz, Knoten)
        using P = std::pair<int, int>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
        pq.push({0, k});

        int settled = 0;  // Anzahl Knoten mit endgültiger Distanz
        int answer = 0;   // Distanz des zuletzt fertig gewordenen Knotens

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) {
                continue;  // veralteter Eintrag — es gibt schon eine bessere Distanz
            }

            ++settled;
            answer = d;

            for (const auto& [v, w] : adj[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return settled == n ? answer : -1;
    }
};
