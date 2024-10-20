#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, s;
    cin >> n >> s;
    n -= (n - 1) / 2; // 1 .. M - 1
    cout << s / n << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}