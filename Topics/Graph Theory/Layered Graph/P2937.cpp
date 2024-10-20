#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
using PIII = tuple<int, int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int dir[][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    int n, m;
    cin >> m >> n;
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    vector<PII> C;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'C') {
                C.emplace_back(i, j);
            }
        }
    }

    auto bfs = [&](auto sx, auto sy) -> int {
        vector<vector<int>> f(n, vector<int>(m, 1e9));
        queue<PIII> q;
        q.push({sx, sy, 0});
        while (!q.empty()) {
            auto [x, y, d] = q.front();
            q.pop();
            for (auto [dx, dy] : dir) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '*') {
                    continue;
                }
                // .. 
            }
        }
        int mn = 1e9;
        for (auto [x, y] : C) {
            if (x == sx && y == sy) {
                continue;
            }
            mn = min(mn, f[x][y]);
        }
        return mn;
    };

    int ans = 1e9;
    for (auto [x, y] : C) {
        ans = min(ans, bfs(x, y));
    }
    cout << ans << '\n';

    return 0;
}