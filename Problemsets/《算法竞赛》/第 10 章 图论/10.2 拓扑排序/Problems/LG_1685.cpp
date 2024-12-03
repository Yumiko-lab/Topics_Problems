#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

constexpr int MOD = 10000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, t, t0;
    cin >> n >> m >> s >> t >> t0;
    s--, t--;
    vector<vector<PII>> adj(n);
    vector<int> din(n);
    vector<int> f(n), g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        din[v]++;
    }

    queue<int> q;
    q.emplace(s);
    f[s] = 1;
    
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto [v, w] : adj[u]) {
            f[v] = (f[v] + f[u]) % MOD;
            g[v] = (g[v] + g[u] + 1LL * f[u] * w % MOD) % MOD;
            if (--din[v] == 0) {
                q.emplace(v);
            }
        }
    }

    cout << (g[t] + (f[t] - 1LL) * t0 % MOD) % MOD << '\n';

    return 0;
}