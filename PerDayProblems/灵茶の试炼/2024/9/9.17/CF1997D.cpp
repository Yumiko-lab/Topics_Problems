#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        adj[p].push_back(i);
    }

    vector<int> f(n); // f[u] : 表示以 u 为根的子树, 最多可以减多少个 1
    auto dfs = [&](auto self, int u) -> int {
        int mn = 1e9;
        for (auto v : adj[u]) {
            int val = self(self, v);
            mn = min(mn, val);
        }
        if (mn == 1e9) { // leaf
            f[u] = a[u];
        } else if (a[u] >= mn) {
            f[u] = mn;
        } else { // a[u] < mn
            f[u] = (a[u] + mn) / 2;
        }
        return f[u];
    };

    dfs(dfs, 0);

    int mn = 1e9;
    for (auto v : adj[0]) {
        mn = min(mn, f[v]);
    }
    cout << a[0] + mn << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}