#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1), sa(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto check = [&](int x) {
        vector s(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            sa[i] = sa[i - 1] + (a[i] >= x ? 1 : -1);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                s[i][j] = (sa[j] - sa[i - 1] > 0 ? 1 : -1);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int c = (s[j][j] - s[i - 1][j] - s[j][i - 1] + s[i - 1][i - 1] > 0 ? 1 : -1); // segs in [i, j]
                ans += c;
            }
        }
        return ans > 0;
    };

    int lo = 1, hi = 1e9;
    while (lo < hi) {
        int mi = (lo + hi + 1) >> 1;
        if (check(mi)) {
            lo = mi;
        } else {
            hi = mi - 1;
        }
    }
    cout << hi << '\n';

    return 0;
}