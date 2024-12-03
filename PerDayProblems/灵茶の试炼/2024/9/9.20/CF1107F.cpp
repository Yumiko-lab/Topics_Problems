#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Info {
    i64 a, b, k;
    bool operator<(const Info &w) const {
        return b > w.b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Info> info(n);
    for (int i = 0; i < n; i++) {
        i64 a, b, k;
        cin >> a >> b >> k;
        info[i] = {a, b, k};
    }
    sort(info.begin(), info.end());

    vector<i64> f(n + 1);
    i64 mx = 0;
    for (auto [a, b, k] : info) {
        for (int j = n; j >= 0; j--) {
            f[j] += max(a - b * k, 0LL);
            if (j > 0) {
                f[j] = max(f[j], f[j - 1] + a - b * (j - 1));
            }
            mx = max(mx, f[j]);
        }
    }
    cout << mx << '\n';

    return 0;
}