#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 20;

int fact[N]; // power of 10

i64 dp(int num) {
    if (num == 0) {
        return 1;
    }
    i64 ans = 0;

    

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * 10;
    }

    i64 l, r;
    cin >> l >> r;

    cout << dp(r) - dp(l - 1) << '\n';

    return 0;
}