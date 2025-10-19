#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const ll INF = 1e18;
const ll MOD = 1e9 + 9;

struct State {
    int node;
    ll dist;
    int cnt;
    bool operator<(const State& other) const {
        if (dist != other.dist) return dist > other.dist;
        return cnt > other.cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, x, y;
    cin >> N >> M;
    cin >> x >> y;

    vector<vector<pii>> G(N+1);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }

    vector<ll> dist(N+1, INF);
    vector<int> nodeCnt(N+1, INT_MAX);
    vector<ll> pathCnt(N+1, 0);

    priority_queue<State> pq;
    pq.push({x, 0, 0});
    dist[x] = 0;
    nodeCnt[x] = 0;
    pathCnt[x] = 1;

    while (!pq.empty()) {
        auto [cur, d, c] = pq.top();
        pq.pop();

        if (d > dist[cur]) continue;
        if (d == dist[cur] && c > nodeCnt[cur]) continue;

        for (auto [nxt, w] : G[cur]) {
            ll nd = d + w;
            int nc = c + 1;

            if (nd < dist[nxt] || (nd == dist[nxt] && nc < nodeCnt[nxt])) {
                dist[nxt] = nd;
                nodeCnt[nxt] = nc;
                pathCnt[nxt] = pathCnt[cur];
                pq.push({nxt, nd, nc});
            } else if (nd == dist[nxt] && nc == nodeCnt[nxt]) {
                pathCnt[nxt] = (pathCnt[nxt] + pathCnt[cur]) % MOD;
            }
        }
    }

    if (dist[y] == INF) cout << -1;
    else cout << dist[y] << "\n" << nodeCnt[y] << "\n" << (pathCnt[y] % MOD);

    return 0;
}
