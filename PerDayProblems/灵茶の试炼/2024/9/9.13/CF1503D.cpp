#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> f(n + 1), flg(n + 1);
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > n && b > n) {
            return cout << -1, 0;
        }
        if (a <= n) {
            f[a] = b;
        } else {
            f[b] = a, flg[b] = 1;
        }
    }

    vector<int> pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++) {
        pre[i] = (i == 1 ? f[i] : min(pre[i - 1], f[i]));
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = (i == n ? f[i] : max(suf[i + 1], f[i]));
    }

    int ans = 0;
    vector<int> kp(1, 0);
    for (int i = 1; i <= n; i++) {
        if (pre[i] > suf[i + 1]) {
            kp.emplace_back(i);
        }
    }

    auto calc = [&](int l, int r) {
        int w = 0;
        stack<int> stk1, stk2;
        for (int i = l; i <= r; i++) {
            if (stk1.empty() || stk1.top() > f[i]) {
                w += flg[i], stk1.push(f[i]);
            } else if (stk2.empty() || stk2.top() > f[i]) {
                w += 1 - flg[i], stk2.push(f[i]);
            } else {
                return cout << -1, 0;
            }
        }
        return min(w, r - l + 1 - w);
    };

    for (int i = 1; i < kp.size(); i++) {
        ans += calc(kp[i - 1] + 1, kp[i]);
    }
    
    cout << ans << '\n';

    return 0;
}