#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100010, M = N * 21;

int n;
int s[N];
int son[M][2], id[M], idx;

void insert(int x, int k) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (!son[p][u]) {
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
    id[p] = k;
}

int search(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (son[p][!u]) {
            p = son[p][!u];
        } else {
            p = son[p][u];
        }
    }
    return id[p];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] ^= s[i - 1];
    }

    insert(s[0], 0);
    array<int, 3> ans{-1};
    for (int i = 1; i <= n; i++) {
        int k = search(s[i]);
        int t = s[i] ^ s[k];
        if (t > ans[0]) {
            ans = {t, k + 1, i};
        }
        insert(s[i], i);
    }

    for (auto x : ans) {
        cout << x << ' ';
    }

    return 0;
}