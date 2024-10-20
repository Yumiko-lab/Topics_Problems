#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<int> a(n);
    vector goods(k, vector<int>());
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        goods[a[i]].emplace_back(i);
    }

    vector adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector dis(k, vector(n, -1));

    auto bfs = [&](auto g) {
        queue<int> q;
        for (auto u : goods[g]) {
            q.push(u);
            dis[g][u] = 0;
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                if (dis[g][v] != -1) {
                    continue;
                }
                dis[g][v] = dis[g][u] + 1;
                q.push(v);
            }
        }
    };

    for (int i = 0; i < k; i++) {
        bfs(i);
    }

    for (int i = 0; i < n; i++) {
        priority_queue<int> q;
        int ans = 0;
        for (int j = 0; j < k; j++) {
            if (q.size() < s) {
                q.push(dis[j][i]);
                ans += dis[j][i];
            } else if (q.top() > dis[j][i]) {
                auto t = q.top();
                q.pop();
                q.push(dis[j][i]);
                ans += dis[j][i] - t;
            }
        }
        cout << ans << ' ';
    }
    cout << '\n';
    
    return 0;
}