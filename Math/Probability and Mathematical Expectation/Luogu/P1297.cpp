#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 100000001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(3);

    int n, A, B, C;
    cin >> n >> A >> B >> C;
    vector<int> a(n + 1);
    cin >> a[1];
    for (int i = 2; i <= n; i++) {
        a[i] = (1LL * a[i - 1] * A % MOD + B) % MOD;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = a[i] % C + 1;
    }

    double ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1.0 / max(a[i], a[i % n + 1]);
    }
    cout << ans << '\n';

    return 0;
}