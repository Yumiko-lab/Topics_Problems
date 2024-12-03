#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, siz;
    int cnt;
    
    DSU() {}
    DSU(int n) : p(n), siz(n, 1), cnt(n) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }
        cnt--;
        siz[y] += siz[x];
        p[x] = y; // x -> y
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    DSU dsu(n);
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '1') {
                deg[i]++;
                dsu.merge(i, j);
            }
        }
    }

    if (dsu.cnt == 1) {
        cout << "0\n";
        return;
    }

    vector<vector<int>> adj(n);
    vector<int> roots;
    for (int i = 0; i < n; i++) {
        if (dsu.size(i) == 1) {
            cout << 1 << '\n' << i + 1 << '\n';
            return;
        }
        adj[dsu.p[i]].emplace_back(i);
        if (dsu.p[i] == i) {
            roots.emplace_back(i);
        }
    }

    for (auto u : roots) {
        for (auto v : adj[u]) {
            if (deg[v] != dsu.siz[u] - 1) {
                array<int, 2> mn {n, -1};
                for (auto x : adj[u]) {
                    if (deg[x] < mn[0]) {
                        mn = {deg[x], x};
                    }
                }
                cout << 1 << '\n' << mn[1] + 1 << '\n';
                return;
            }
        }
    }

    if (dsu.cnt == 2) {
        int r = (dsu.size(roots[0]) > dsu.size(roots[1]) ? roots[1] : roots[0]);
        cout << dsu.size(r) << '\n';
        for (auto v : adj[r]) {
            cout << v + 1 << ' ';
        }
        cout << '\n';
        return;
    }
    cout << 2 << '\n';
    cout << adj[roots[0]][0] + 1 << ' ' << adj[roots[1]][0] + 1 << '\n';
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