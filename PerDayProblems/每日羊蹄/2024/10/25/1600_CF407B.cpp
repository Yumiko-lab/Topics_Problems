#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        f[i] = 2;
        for (int j = a[i]; j < i; j++) {
            f[i] = (f[i] + f[j]) % MOD;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + f[i]) % MOD;
    }
    cout << ans << '\n';

    return 0;
}