#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5010, M = 5010 * 3;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dis[N];
int q[N], cnt[N];
bool in[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof h);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        add(x2, x1, y);
    }

    for (int i = 1; i <= n; i++) {
        add(0, i, 0);
    }

    auto spfa = [&]() {
        memset(dis, 0x3f, sizeof dis);
        dis[0] = 0;
        int hh = 0, tt = 0;
        q[0] = 0;
        in[0] = true;
        while (hh <= tt) {
            auto u = q[tt--];
            in[u] = false;
            for (int i = h[u]; ~i; i = ne[i]) {
                int v = e[i];
                if (dis[v] > dis[u] + w[i]) {
                    dis[v] = dis[u] + w[i];
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] >= n + 1) {
                        return false;
                    }
                    if (!in[v]) {
                        in[v] = true;
                        q[++tt] = v;
                    }
                }
            }
        }
        return true;
    };

    if (!spfa()) {
        return cout << "NO\n", 0;
    }

    for (int i = 1; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << '\n';

    return 0;
}