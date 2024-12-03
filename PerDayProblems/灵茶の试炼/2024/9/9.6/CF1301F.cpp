#include <bits/stdc++.h>
using namespace std;

constexpr int dir[][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector g(n, vector<int>(m));
    vector col(k, vector<pair<int, int>>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            g[i][j]--;
            col[g[i][j]].push_back({i, j});
        }
    }

    vector cost(k, vector(n, vector<int>(m, -1)));
    vector<bool> done(k);
    
    auto bfs = [&](auto c) {
        done.assign(k, 0);
        queue<pair<int, int>> q;
        for (auto [x, y] : col[c]) {
            done[c] = true;
            cost[c][x][y] = 0;
            q.push({x, y});
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto &[dx, dy] : dir) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= n || b < 0 || b >= m || cost[c][a][b] != -1) {
                    continue;
                }
                cost[c][a][b] = cost[c][x][y] + 1;
                q.push({a, b});
            }
            if (!done[g[x][y]]) {
                done[g[x][y]] = true;
                for (auto [a, b] : col[g[x][y]]) {
                    if (cost[c][a][b] == -1) {
                        cost[c][a][b] = cost[c][x][y] + 1;
                        q.push({a, b});
                    }
                }
            }
        }
    };

    for (int i = 0; i < k; i++) {
        bfs(i);
    }
    
    int q;
    cin >> q;
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--, r2--, c2--;
        int ans = abs(r1 - r2) + abs(c1 - c2);
        for (int i = 0; i < k; i++) {
            ans = min(ans, 1 + cost[i][r1][c1] + cost[i][r2][c2]);
        }
        cout << ans << '\n';
    }

    return 0;
}