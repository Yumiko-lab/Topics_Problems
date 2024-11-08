#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(2);

    int n, m;
    cin >> n >> m;
    vector<vector<PII>> adj(n);
    vector<double> f(n, -1);
    vector<int> dout(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w); // u -> v
        dout[u]++;
    }

    auto dp = [&](auto self, int u) -> double {
        if (f[u] >= 0) { // Floating point comparison (not f[u] != -1)
            return f[u];
        }
        f[u] = 0;
        for (auto [v, w] : adj[u]) {
            f[u] += (self(self, v) + w) / dout[u];
        }
        return f[u];
    };

    cout << dp(dp, 0) << '\n';

    return 0;
}