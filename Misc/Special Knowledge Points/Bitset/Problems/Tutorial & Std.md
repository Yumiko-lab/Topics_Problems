# Bitset 相关例题

## BZOJ 3687 简单题

> Description：
>
> 给定数组 $a_{1 \sim n}$，求所有子集和的异或和。

[BZOJ P3687. 简单题](https://hydro.ac/p/bzoj-P3687) 

- 状态表示：

$f(i, j)$：考虑前 $i$ 个数，和为 $j$ 的方案的奇偶性。

- 状态计算：

$$
f(i, j) = f(i - 1, j) \oplus f(i - 1, j - a_i)
$$

直接转移的时间复杂度：$\mathcal O(n \times \sum a_i \approx 1000 \times 2 \times 10^6 = 2 \times 10^9)$ —— 时空复杂度都爆



bitset 优化 —— 

首先 $f$ 数组首先优化掉第一维，然后第二维用 bitset 代替。


时空复杂度：$\mathcal O(\dfrac {n \times \sum a_i}{w})$。




```cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2000010;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    bitset<N> f {};
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f = f ^ (f << x); // f[i][j] = f[i - 1][j] ^ f[i - 1][j - x];
    }

    int ans = 0;
    for (int i = 1; i <= 2E6; i++) {
        if (f[i]) {
            ans ^= i;
        }
    }
    cout << ans << '\n';

    return 0;
}
```


## LG P10480 可达性统计

```cpp
#include <bits/stdc++.h>
#include <bitset>
using namespace std;

constexpr int N = 30010;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> ind(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        ind[v]++;
    }

    vector<int> seq;
    auto topo = [&]() {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0) {
                q.emplace(i);
            }
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            seq.emplace_back(u);
            for (auto v : adj[u]) {
                if (--ind[v] == 0) {
                    q.emplace(v);
                }
            }
        }
    };

    topo();

    bitset<N> f[n] {};

    for (int i = seq.size() - 1; i >= 0; i--) {
        int u = seq[i];
        f[u][u] = 1;
        for (auto v : adj[u]) {
            f[u] |= f[v];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << f[i].count() << '\n';
    }

    return 0;
}
```

## BZOJ 4503 两个串

[BZOJ P4503. 两个串](https://hydro.ac/p/bzoj-P4503) 

> Description：
>
> 给定两个串 $S$ 和 $T$，求 $T$ 在 $S$ 中出现了几次，分别在哪些位置出现。


KMP 无法解决通配符问题


```cpp

```


## CF577B. Modulo Sum


[Codeforces Round 319 (Div. 2) - B. Modulo Sum](https://codeforces.com/problemset/problem/577/B) 

> Description：
>
> 


[Bellala - Blog](https://www.cnblogs.com/wushansinger/p/15950987.html) 



> 正解并不是 bitset，但是可以用 bitset 水过。


经典的 01 背包，但是直接做复杂度是 $\mathcal O(nm)$ 会超时。

对于某个数 $x$，可以只选 $x$，或者把前面的所有方案都加上 $x$ (即左移 $x$ 位)，左移超过 $m$ 位的部分需要需要减去 $m$，相当于左移 $x$ 位再右移 $m$ 位，即右移 $m - x$ 位。




```cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1010;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    bitset<N> f {};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x %= m;
        f = f | (f << x) | (f >> (m - x));
        f[x] = 1; // 只选 x 本身
    }

    cout << (f[0] ? "YES" : "NO") << '\n';

    return 0;
}
```

