#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    i64 sum = 0;
    vector s(3, vector<i64>(n + 1));
    for (auto t : {0, 1, 2}) {
        for (int i = 1; i <= n; i++) {
            cin >> s[t][i];
            if (t == 0) {
                sum += s[t][i];
            }
            s[t][i] += s[t][i - 1];
        }
    }

    vector<int> t = {0, 1, 2};
    vector<array<int, 2>> ans(3);

    auto get = [&](auto t, int l) {
        int lo = l, hi = n + 1;
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            if (3 * (s[t][mi] - s[t][l - 1]) >= sum) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        int ans = hi;
        if (hi == n + 1) {
            ans = -1;
        }
        return ans;
    };

    bool suc = false;
    do {
        bool ok = true;
        int l = 1;
        for (auto v : t) {
            int r = get(v, l);
            if (r == -1) {
                ok = false;
                break;
            }
            ans[v] = {l, r};
            l = r + 1;
        }
        if (ok) {
            suc = true;
            break;
        }
    } while (next_permutation(t.begin(), t.end()));

    if (suc) {
        for (auto t : {0, 1, 2}) {
            cout << ans[t][0] << ' ' << ans[t][1] << ' ';
        }
        cout << '\n';
    } else {
        cout << "-1\n";
    }
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