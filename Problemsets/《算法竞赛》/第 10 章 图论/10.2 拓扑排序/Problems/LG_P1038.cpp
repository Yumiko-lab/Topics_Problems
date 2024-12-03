#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<PII>> adj(n);
    vector<int> c(n);
    vector<int> din(n), dout(n);
    int u;
    for (int i = 0; i < n; i++) {
        cin >> u >> c[i];
        c[i] -= u;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        dout[u]++, din[v]++;
    }

    auto topo = [&]() {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (din[i] == 0 && c[i] > 0) {
                q.emplace(i);
            }
        }
        
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto [v, w] : adj[u]) {
                c[v] += (c[u] * w);
                if (--din[v] == 0) {
                    q.emplace(v);
                }
            }
        }
    };

    topo();

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (dout[i] == 0 && c[i] > 0) {
            ans.emplace_back(i);
        }
    }
    if (ans.empty()) {
        return cout << "NULL\n", 0;
    }

    for (auto x : ans) {
        cout << x + 1 << ' ' << c[x] << '\n';
    }
    cout << '\n';

    return 0;
}