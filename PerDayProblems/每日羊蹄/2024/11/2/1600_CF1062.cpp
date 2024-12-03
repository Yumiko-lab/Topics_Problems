#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1'000'000'007;

int power(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = 1LL * a * a % MOD) {
        if (b & 1) {
            res = 1LL * res * a % MOD;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    string str;
    cin >> n >> q >> str;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + (str[i - 1] == '1');
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int x = s[r] - s[l - 1], y = r - l + 1 - x;
        // 2^{x - 1} * 2^y        
        cout << 1LL * (power(2, x) - 1) * power(2, y) % MOD << '\n';
    }

    return 0;
}