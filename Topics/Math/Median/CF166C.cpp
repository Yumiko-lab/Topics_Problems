#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    
    vector<int> a(1, 0);
    bool has = false;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a.emplace_back(v);
        if (v == x) {
            has = true;
        }
    }

    int ans = 0;
    if (!has) {
        ans++, n++;
        a.emplace_back(x);
    }

    ranges::sort(a);

    int lo = lower_bound(a.begin(), a.end(), x) - a.begin(), hi = upper_bound(a.begin(), a.end(), x) - a.begin() - 1;

    int mi = (n + 1) / 2;

    if (mi >= lo && mi <= hi) {
        cout << ans << '\n';
        return 0;
    }

    if (lo > mi) {
        ans += (lo - 1 - (n - lo));
    } else {
        ans += (n - hi - hi);
    }

    cout << ans << '\n';
    
    return 0;
}