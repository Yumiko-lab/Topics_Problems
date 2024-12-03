#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100010, M = N * 31;

int n, m;
int s[N];
int son[M][2], cnt[M], idx;

void insert(int x, int v) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (!son[p][u]) {
            son[p][u] = ++idx;
        }
        p = son[p][u];
        cnt[p] += v;
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (cnt[son[p][!u]]) {
            p = son[p][!u], res |= 1 << i;
        } else {
            p = son[p][u];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] ^= s[i - 1];
    }

    insert(s[0], 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (i - m - 1 >= 0) {
            insert(s[i - m - 1], -1);
        }
        mx = max(mx, query(s[i])); // i - m, i - 1
        insert(s[i], 1);
    }

    cout << mx << '\n';
    
    return 0;
}