#include <iostream>
#include <algorithm>
#include <set>
#define int long long
using namespace std;

const int N = 110, M = 5010;

int n, m;
struct Edge {
    int u, v, w;
    bool operator<(const Edge &t) const {
        return w < t.w;
    }
} e[M];

int p[N];

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    sort(e, e + m);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    int res = 0;
    set<int> S;
    bool flg = true;
    for (int i = 0; i < m; i++) {
        int u = find(e[i].u), v = find(e[i].v), w = e[i].w;
        if (u != v) {
            p[u] = v;
            res += w;
            S.insert(w);
        } else if (S.count(w)) {
            flg = false;
            break;
        }
    }
    if (!flg) {
        cout << "Not Unique!\n";
        return;
    }
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}