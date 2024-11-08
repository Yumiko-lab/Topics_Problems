#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

#define x first
#define y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    auto dfs = [&](auto self, int u, int from = -1, int dis = 0) -> PII {
        p[u] = from;
        PII res = {dis, u};
        for (auto v : adj[u]) {
            if (v == from) {
                continue;
            }
            res = max(res, self(self, v, u, dis + 1));
        }
        return res;
    };

    PII da = dfs(dfs, 0);
    PII db = dfs(dfs, da.y);

    vector<int> dia; // diameter
    int u = db.y;
    while (u != -1) {
        dia.emplace_back(u);
        u = p[u];
    }

    if (dia.size() == n) {
        cout << n - 1 << '\n';
        cout << dia[0] + 1 << ' ' << dia[1] + 1 << ' ' << dia.back() + 1 << '\n';
        return 0;
    }

    vector<int> dis(n, -1);
    auto bfs = [&]() {
        queue<int> q;
        for (auto x : dia) { // multi-source bfs
            q.push(x);
            dis[x] = 0;
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                if (dis[v] != -1) {
                    continue;
                }
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    };

    bfs();

    PII mx = {dis[0], 0};
    for (int i = 1; i < n; i++) {
        mx = max(mx, {dis[i], i});
    }

    cout << dia.size() - 1 + mx.x << '\n';

    cout << dia[0] + 1 << ' ' << dia.back() + 1 << ' ' << mx.y + 1 << '\n';
    
    return 0;
}