#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100010, M = 26;

int n, m;
int son[N][M], cnt[N], idx;
char s[N];

void insert(string &s) {
    int p = 0;
    for (auto c : s) {
        int u = c - 'a';
        if (!son[p][u]) {
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string &s) {
    int p = 0, res = 0;
    for (auto c : s) {
        int u = c - 'a';
        if (!son[p][u]) {
            return res;
        }
        p = son[p][u];
        res += cnt[p];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(s);
    }
    
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        cout << query(s) << '\n';
    }

    return 0;
}