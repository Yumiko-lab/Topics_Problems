#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100010, M = N * 2, K = N * 31;

int n;
int h[N], e[M], w[M], ne[M], idx;
int dis[N]; // dis[u] : 节点 u 到根节点的路径上的所有边权的异或和
int son[K][2];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (!son[p][u]) {
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (son[p][!u]) {
            p = son[p][!u], res |= 1 << i;
        } else {
            p = son[p][u];
        }
    }
    return res;
}

void dfs(int u, int from) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == from) {
            continue;
        }
        dis[v] = dis[u] ^ w[i];
        dfs(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }

    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        insert(dis[i]);
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, query(dis[i]));
    }
    cout << mx << '\n';

    return 0;
}