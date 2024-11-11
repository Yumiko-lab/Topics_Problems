#include <bits/stdc++.h>
#include <bitset>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> din(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        din[v]++;
    }

    vector<int> seq;
    auto topo = [&]() {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (din[i] == 0) {
                q.emplace(i);
            }
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            seq.emplace_back(u);
            for (auto v : adj[u]) {
                if (--din[v] == 0) {
                    q.emplace(v);
                }
            }
        }
    };

    topo();

    bitset<30010> f[n] {};

    for (int i = seq.size() - 1; i >= 0; i--) {
        int u = seq[i];
        f[u][u] = 1;
        for (auto v : adj[u]) {
            f[u] |= f[v];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << f[i].count() << '\n';
    }

    return 0;
}