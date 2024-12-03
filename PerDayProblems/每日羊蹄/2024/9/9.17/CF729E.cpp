#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    vector<int> cnt(n);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i == s) {
            ans += (x > 0);
        } else {
            cnt[x]++;
        }
    }

    int cur = 0;
    for (int i = 1; cur < n - 1; i++) {
        if (cnt[i]) {
            cur += cnt[i];
        } else {
            cur++, ans++; // 后面选一个 > i 的变成 i ( 由于 cur < n - 1 所以一定可以操作 )
        }
    }

    cout << ans << '\n';

    return 0;
}