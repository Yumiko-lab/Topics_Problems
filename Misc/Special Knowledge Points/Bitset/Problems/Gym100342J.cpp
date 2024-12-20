#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 1510;

int n;
char s[N][N];
bitset<N> out[N], in[N]; // out[i]: 从 i 出发能遍历到的点的集合, in[i]: 可以遍历到 i 的点的集合

int main() {
    // freopen("triatrip.in", "r", stdin);
    // freopen("triatrip.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < n; j++) { // i -> j
            if (s[i][j] == '+') {
                out[i][j] = 1;
                in[j][i] = 1;
            }
        }
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '+') { // 遍历所有边
                ans += (in[i] & out[j]).count();
            }
        }
    }
    cout << ans / 3 << '\n';

    return 0;
}