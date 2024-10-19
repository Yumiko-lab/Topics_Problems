#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    bitset<2000010> f{};
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f = f ^ (f << x);
    }

    int ans = 0;
    for (int i = 1; i <= 2E6; i++) {
        if (f[i]) {
            ans ^= i;
        }
    }
    cout << ans << '\n';

    return 0;
}