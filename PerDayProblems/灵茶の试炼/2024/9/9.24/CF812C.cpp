#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {

    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    auto check = [&](auto k) {
        vector<i64> b(n);
        i64 now = 0;
        priority_queue<i64> q;
        if (k == 0) {
            return ans = 0, true;
        }
        for (int i = 0; i < n; i++) { // Instead of sort(b), pq has relatively small constant
            b[i] = a[i] + (i + 1LL) * k;
            if (q.size() < k) {
                q.push(b[i]);
                now += b[i];
            } else if (q.top() > b[i]) {
                auto t = q.top();
                q.pop();
                q.push(b[i]);
                now += b[i] - t;
            }
        }
        if (now > s) {
            return false;
        }
        return ans = now, true;
    };

    int lo = 0, hi = n;
    while (lo < hi) {
        int mi = (lo + hi + 1) >> 1;
        if (check(mi)) {
            lo = mi;
        } else {
            hi = mi - 1;
        }
    }

    check(hi);

    cout << hi << ' ' << ans << '\n';

    return 0;
}