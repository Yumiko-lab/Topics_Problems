#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    string s;
    cin >> n >> s >> x >> y;

    map<char, pair<int, int>> mp;
    mp['U'] = {0, 1};
    mp['D'] = {0, -1};
    mp['L'] = {-1, 0};
    mp['R'] = {1, 0};

    if (abs(x) + abs(y) > n || (x + y - n) & 1) {
        return cout << -1, 0;
    }

    vector<int> acc_x(n + 1, 0), acc_y(n + 1, 0);

    for (int i = 0; i < n; i++) {
        auto &[dx, dy] = mp[s[i]];
        acc_x[i + 1] = acc_x[i] + dx;
        acc_y[i + 1] = acc_y[i] + dy;
    }

    auto check = [&](int l, int r) { // Abstract prefix sum
        return abs(acc_x[l] + acc_x[n] - acc_x[r] - x) + abs(acc_y[l] + acc_y[n] - acc_y[r] - y) > r - l;
    };

    int l = 0, r = 0, ans = n + 1;
    while (l <= r) { // (l, r]
        while (r < n && check(l, r)) {
            r++;
        }
        if (check(l, r)) {
            break;
        }
        ans = min(ans, r - l);
        l++;
    }
    cout << ans << '\n';

    return 0;
}