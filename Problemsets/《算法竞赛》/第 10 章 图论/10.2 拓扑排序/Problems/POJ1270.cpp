#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 20, M = 26, K = 55;

int n;
int v[N], seq[N];
int g[M][M], din[M];
bool vis[M];
char s[K];

void dfs(int u) {
    if (u == n) { // 0 .. n - 1
        for (int i = 0; i < n; i++) {
            cout << (char)(seq[i] + 'a');
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[v[i]] && din[v[i]] == 0) {
            vis[v[i]] = 1;
            seq[u] = v[i];
            for (int j = 0; j < n; j++) {
                if (!vis[v[j]] && g[v[i]][v[j]]) {
                    din[v[j]]--;
                }
            }
            dfs(u + 1);
            vis[v[i]] = 0;
            for (int j = 0; j < n; j++) {
                if (!vis[v[j]] && g[v[i]][v[j]]) {
                    din[v[j]]++;
                }
            }
        }
    }
}

int main() {
    while (fgets(s, 100, stdin) != NULL) {
        memset(g, 0, sizeof g);
        memset(din, 0, sizeof din);
        int len = strlen(s);
        n = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                v[n++] = s[i] - 'a';
            }
        }
        sort(v, v + n); // 按照字典序输出
        
        // 建图
        fgets(s, 100, stdin);
        len = strlen(s);
        char first = '^'; // "^$";
        for (int i = 0; i < len; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                if (first == '^') {
                    first = s[i];
                } else {
                    int x = first - 'a', y = s[i] - 'a';
                    g[x][y] = 1;
                    din[y]++;
                    first = '^';
                }
            }
        }
        
        dfs(0);
        cout << '\n';
    }

    return 0;
}


/*

Problems: https://vjudge.net/problem/POJ-1270

*/