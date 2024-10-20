#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    ranges::sort(a);

    auto check = [&](auto x) {
        i64 ned = 0;
        for (int i = n / 2; i < n; i++) {
            ned += max(0LL, x - a[i]);
        }
        return ned <= k;
    };

    int lo = 0, hi = 2e9;
    while (lo < hi) {
        i64 mi = (lo + 1LL + hi) >> 1;
        if (check(mi)) {
            lo = mi;
        } else {
            hi = mi - 1;
        }
    }

    cout << hi << '\n';
    
    return 0;
}