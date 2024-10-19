#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int M = 2000010;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> f(M);
    f[0] = 1;
    for (auto x : a) {
        for (int j = M - 1; j >= x; j--) {
            f[j] ^= f[j - x];
        }
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (f[i]) {
            ans ^= i;
        }
    }

    cout << ans << '\n';

    return 0;
}