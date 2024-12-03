#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 80112002;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> din(n), dout(n), cnt(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        dout[u]++, din[v]++;
    }

    auto topo = [&]() {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (din[i] == 0) {
                cnt[i] = 1;
                q.emplace(i);
            }
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                cnt[v] = (cnt[v] + cnt[u]) % 80112002;
                if (--din[v] == 0) {
                    q.emplace(v);
                }
            }
        }
    };

    topo();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dout[i] == 0) {
            ans = (ans + cnt[i]) % MOD;
        }
    }
    cout << ans << '\n';

    return 0;
}