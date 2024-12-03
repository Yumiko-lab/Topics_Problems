#include <bits/stdc++.h>
using namespace std;

constexpr double eps = 1e-4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    while (cin >> n >> k, n || k) {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        auto check = [&](auto x) {
            vector<double> c(n);
            for (int i = 0; i < n; i++) {
                c[i] = 100.0 * a[i] - x * b[i];
            }
            sort(c.begin(), c.end(), greater<double>());
            double ans = 0;
            for (int i = 0; i < n - k; i++) {
                ans += c[i];
            }
            return ans >= 0;
        };
        
        double lo = 0, hi = 100;
        while (hi - lo > eps) {
            double mi = (lo + hi) / 2;
            if (check(mi)) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        cout << (int)(hi + 0.5) << '\n';
    }

    return 0;
}