#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] % 4 == 0) {
            ans++;
        }
        if (i - 1 >= 0 && (s[i - 1] * 10 + s[i]) % 4 == 0) {
            ans += i;
        }
    }
    cout << ans << '\n';

    return 0;
}