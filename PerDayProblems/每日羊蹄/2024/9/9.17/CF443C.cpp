#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (auto &x : a) {
        cin >> x;
    }

    i64 orig = 0;
    vector<i64> cur(n + 1);
    vector<vector<int>> tmp(n + 1);

    for (int i = 1; i < m; i++) {
        int v = abs(a[i] - a[i - 1]);
        orig += v;

        if (a[i] != a[i - 1]) {
            cur[a[i]] += v;
            cur[a[i - 1]] += v;
            tmp[a[i]].emplace_back(a[i - 1]);
            tmp[a[i - 1]].emplace_back(a[i]);
        }
    }

    i64 res = 0;
    for (int i = 1; i <= n; i++) {
        if (tmp[i].size()) {
            ranges::sort(tmp[i]);
            int x = tmp[i][tmp[i].size() / 2];

            i64 cur_res = 0;
            for (auto &v : tmp[i]) {
                cur_res += abs(v - x);
            }
            res = max(res, cur[i] - cur_res);
        }
    }
    cout << orig - res << '\n';

    return 0;
}