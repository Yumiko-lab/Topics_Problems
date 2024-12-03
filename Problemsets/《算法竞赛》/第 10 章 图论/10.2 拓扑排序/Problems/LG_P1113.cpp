#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1), f(n + 1);
    vector<int> din(n + 1);
    vector<vector<PII>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        cin >> a[v];
        f[v] = a[v];
        int u;
        while (cin >> u, u) {
            adj[u].emplace_back(v, a[v]);
            din[v]++;
        }
    }
    adj[0].emplace_back(1, a[1]);
    din[1]++;

    auto topo = [&]() {
        queue<int> q;
        q.emplace(0);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto [v, w] : adj[u]) {
                f[v] = max(f[v], f[u] + w);
                if (--din[v] == 0) {
                    q.emplace(v);
                }
            }
        }
    };

    topo();

    cout << *max_element(f.begin(), f.end()) << '\n';

    return 0;
}