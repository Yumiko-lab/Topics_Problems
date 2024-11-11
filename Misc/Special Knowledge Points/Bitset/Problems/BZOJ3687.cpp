#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2000010;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    bitset<N> dp {};
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dp = dp ^ (dp << x);
    }

    int ans = 0;
    for (int i = 1; i <= 2E6; i++) {
        if (dp[i]) {
            ans ^= i;
        }
    }
    cout << ans << '\n';

    return 0;
}