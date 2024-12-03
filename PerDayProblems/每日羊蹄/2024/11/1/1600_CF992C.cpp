#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int MOD = 1'000'000'007;

int power(int a, i64 b) {
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

    i64 n, k;
    cin >> n >> k;

    // cout << (n * power(2, k + 1) % MOD + MOD - () * (MOD + 1) / 2 % MOD) % MOD << '\n';

    return 0;
}