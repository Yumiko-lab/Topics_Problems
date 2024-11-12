#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 5E3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector r(m, vector<int>(n));
    vector f(n, ~bitset<N>{});
    vector<int> o;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> r[i][j];
        }
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int x, int y) {
            return r[i][x] < r[i][y];
        });
        o = ord;
        bitset<N> s{};
        for (int j = 0, k = 0; j < n; j++) {
            while (k < j && r[i][ord[k]] < r[i][ord[j]]) {
                s.set(ord[k]);
                k++;
            }
            f[ord[j]] &= s;
        }
    }

    vector<i64> dp(n);
    for (auto x : o) {
        dp[x] = p[x];
        for (int y = 0; y < n; y++) {
            if (f[x][y]) { // x > y
                dp[x] = max(dp[x], dp[y] + p[x]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
    
    return 0;
}