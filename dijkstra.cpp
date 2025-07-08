#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18

typedef pair<int, int> pii;

vector<int> dijkstra(int start, vector<vector<pii>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int start;
    cin >> start;
    vector<int> distances = dijkstra(start, graph);
    for (int i = 0; i < n; ++i)
        cout << distances[i] << '\n';
}
