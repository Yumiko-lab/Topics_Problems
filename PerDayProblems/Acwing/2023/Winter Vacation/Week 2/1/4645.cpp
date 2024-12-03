#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100010, M = (1 << 20);

int n, m, x;
int a[N];
int f[N], g[M];

/*

f[i] : 表示 1 .. i 中, 满足两个下标不同的数 {a[l], a[r]} 异或为 x 的 l 的最大值
g[x] : 表示 x 最靠右的位置

*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        f[i] = max(f[i - 1], g[a ^ x]);
        g[a] = i;
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << (f[r] >= l ? "yes" : "no") << '\n';
    }

    return 0;
}