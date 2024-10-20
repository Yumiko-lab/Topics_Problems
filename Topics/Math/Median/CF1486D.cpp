#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), s(n + 1), mn(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto check = [&](auto x) {
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + (a[i] >= x ? 1 : -1);
            mn[i] = min(mn[i - 1], s[i]); // Save Choise mn[0] = 0
            if (i >= k && s[i] > mn[i - k]) {
                return true;
            }
        }
        return false;
    };

    int lo = 1, hi = n;
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