#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> ind(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[v].emplace_back(u); // 反图: u -> v  =>  v -> u
        ind[u]++;
    }

    vector<int> seq;
    auto topo = [&]() {
        priority_queue<int> q;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0) {
                q.emplace(i);
            }
        }
        while (!q.empty()) {
            auto u = q.top();
            q.pop();
            seq.emplace_back(u);
            for (auto v : adj[u]) {
                if (--ind[v] == 0) {
                    q.emplace(v);
                }
            }
        }
    };

    topo();
    
    if (seq.size() < n) {
        cout << "Impossible!\n";
        return;
    }

    for (int i = seq.size() - 1; i >= 0; i--) {
        cout << seq[i] + 1 << ' ';
    }
    cout << '\n';
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