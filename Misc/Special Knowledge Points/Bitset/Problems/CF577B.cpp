#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1010;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    bitset<N> f{};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x %= m;
        f = f | (f << x) | (f >> (m - x));
        f[x] = 1; // 只选 x 本身
    }

    cout << (f[0] ? "YES" : "NO") << '\n';

    return 0;
}