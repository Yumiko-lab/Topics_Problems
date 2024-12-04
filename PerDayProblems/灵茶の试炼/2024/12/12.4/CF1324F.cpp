#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> f(n), g(n);

    auto dfs = [&](auto self, int u, int from) -> void {
        f[u] = (a[u] == 1 ? 1 : -1);
        for (auto v : adj[u]) {
            if (v == from) {
                continue;
            }
            self(self, v, u);
            f[u] = max(f[u], f[u] + f[v]);
        }
    };

    dfs(dfs, 0, -1);

    auto dp = [&](auto self, int u, int from) -> void {
        for (auto v : adj[u]) {
            if (v == from) {
                continue;
            }
            g[v] = f[u] + g[u] - (f[v] > 0 ? f[v] : 0);
            self(self, v, u);
        }
    };

    dp(dp, 0, -1);

    // for (int i = 0; i < n; i++) {
    //     cout << f[i] << ' ';
    // }

    // cout << "\n---\n";

    // for (int i = 0; i < n; i++) {
    //     cout << g[i] << ' ';
    // }

    // cout << "\n---\n";

    for (int i = 0; i < n; i++) {
        cout << max(f[i], f[i] + g[i]) << ' ';
    }
    cout << '\n';

    return 0;
}

/**
 * f[i]: 在以节点 i 为根的子树内的连通块的最大 cnt_w - cnt_b 的值
 * g[i]: ..              子树外 (连向父节点)
 */