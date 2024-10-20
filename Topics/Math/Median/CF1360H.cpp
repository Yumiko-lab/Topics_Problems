#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    i64 M = ((1LL << m) - n - 1) / 2;
    bitset<64> num;
    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i] = num.to_ullong();
    }
    ranges::sort(a);
    for (auto x : a) {
        if (x > M) {
            break;
        } else {
            M++;
        }
    }
    num = M;
    for (int i = m - 1; i >= 0; i--) {
        cout << num[i];
    }
    cout << '\n';
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