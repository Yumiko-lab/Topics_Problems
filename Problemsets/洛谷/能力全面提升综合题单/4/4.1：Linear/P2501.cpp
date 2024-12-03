#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mn = a[n - 1];
    i64 cnt = 0, ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < mn) {
            mn = a[i];
        } else {
            ans += a[i] - mn + 1;
            cnt++, mn--;
        }
    }
    cout << cnt << '\n' << ans << '\n';

    return 0;
}