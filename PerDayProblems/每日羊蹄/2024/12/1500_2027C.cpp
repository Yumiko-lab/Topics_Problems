#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    map<i64, vector<i64>> adj;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        i64 u = a[i] + i, v = u + i;
        adj[u].push_back(v); // space: O(n)
    }
    set<i64> vis;
    auto dfs = [&](auto self, i64 u) -> void {
        if (vis.count(u)) {
            return;
        }
        vis.insert(u);
        for (auto v : adj[u]) {
            self(self, v);
        }
    };
    dfs(dfs, n);
    cout << *vis.rbegin() << '\n';
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