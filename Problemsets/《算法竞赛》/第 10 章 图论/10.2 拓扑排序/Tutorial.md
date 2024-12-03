# 拓扑排序相关题目


## LG P1113 杂务

[P1113 杂务](https://www.luogu.com.cn/problem/P1113) 


$f(x) = \max\{f_{y \in pre(x)}(y)\} + a(x)$

( $pre(x)$ 表示 $x$ 的前驱节点集合 )

更新节点 $x$，需要知道其所有前驱的信息，因此需要建反图。



### 拓扑排序

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), f(n), ind(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        u--;
        cin >> a[i];
        f[i] = a[i];
        int v;
        while (cin >> v, v) {
            v--;
            adj[v].emplace_back(u); // 反图: u -> v  =>  v -> u
            ind[u]++;
        }
    }

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
            for (auto v : adj[u]) {
                f[v] = max(f[v], f[u] + a[v]);
                if (--ind[v] == 0) {
                    q.emplace(v);
                }
            }
        }
    };

    topo();

    cout << *max_element(f.begin(), f.end()) << '\n';

    return 0;
}
```

### 正图：点权 $\rightarrow$ 边权 + 拓扑排序


有边 $u \rightarrow v$，将点 $v$ 的点权放到 $u \rightarrow v$ 的路径上。


虚拟源点 $0$ 初始连向所有点，边权是从该点的点权。

( 初始建立一条从 $0$ 到 $1$ 号点的边，将 $1$ 号点的点权放到这条边上 )

题目就转化为了从 $0$ 作为起点的最长路。


```cpp
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1), f(n + 1);
    vector<int> ind(n + 1);
    vector<vector<PII>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        cin >> a[v];
        f[v] = a[v];
        int u;
        while (cin >> u, u) {
            adj[u].emplace_back(v, a[v]);
            ind[v]++;
        }
    }
    adj[0].emplace_back(1, a[1]);
    ind[1]++;

    auto topo = [&]() {
        queue<int> q;
        q.emplace(0);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto [v, w] : adj[u]) {
                f[v] = max(f[v], f[u] + w);
                if (--ind[v] == 0) {
                    q.emplace(v);
                }
            }
        }
    };

    topo();

    cout << *max_element(f.begin(), f.end()) << '\n';

    return 0;
}
```

( 以上两种方法都可以写成记忆化搜索的形式，下面是第一种方法的记忆化搜索写法 )

### 记忆化搜索

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), f(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        u--;
        cin >> a[i];
        int v;
        while (cin >> v, v) {
            v--;
            adj[v].emplace_back(u); // 反图: u -> v  =>  v -> u
        }
    }

    auto dfs = [&](auto self, int u) -> int {
        if (f[u] > 0) {
            return f[u];
        }
        f[u] = a[u];
        for (auto v : adj[u]) {
            f[u] = max(f[u], self(self, v) + a[u]);
        }
        return f[u];
    };

    for (int i = 0; i < n; i++) {
        dfs(dfs, i);
    }

    cout << *max_element(f.begin(), f.end()) << '\n';

    return 0;
}
```


## LG P1685 游览

[P1685 游览](https://www.luogu.com.cn/problem/P1685) 

题目等价于求从起点 $s$ 到终点 $t$ 的所有路径的长度的和。

图上拓扑序 DP。

$f(i)$：表示从 $s$ 到 $i$ 的路径的条数。

$g(i)$：表示从 $s$ 到 $i$ 的所有路径的长度的和。

假设存在一条 $u \rightarrow v$ 的边权为 $w$ 的边：

$f(v) \leftarrow f(v) + f(u)$

$g(v) \leftarrow g(v) + (g(u) + f(u) \times w)$


初始状态：$f(s) = 1$

答案：$g(t) + (f(t) - 1) \times t_0$

( $f(t) - 1$：表示一共需要返回 $总路径条数-1$ 次，每一次花费的时间是 $t_0$ )


```cpp
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

constexpr int MOD = 10000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, t, t0;
    cin >> n >> m >> s >> t >> t0;
    s--, t--;
    vector<vector<PII>> adj(n);
    vector<int> ind(n);
    vector<int> f(n), g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        ind[v]++;
    }

    queue<int> q;
    q.emplace(s);
    f[s] = 1;
    
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto [v, w] : adj[u]) {
            f[v] = (f[v] + f[u]) % MOD;
            g[v] = (g[v] + g[u] + 1LL * f[u] * w % MOD) % MOD;
            if (--ind[v] == 0) {
                q.emplace(v);
            }
        }
    }

    cout << (g[t] + (f[t] - 1LL) * t0 % MOD) % MOD << '\n';

    return 0;
}
```

## LG P3243 [HNOI2015] 菜肴制作


[P3243 [HNOI2015] 菜肴制作](https://www.luogu.com.cn/problem/P3243) 


> 错误方法：正图 + 最小堆 —— 求**字典序最小**的方案
>
> 例如以下这个数据：
> ```cpp
> 1
> 4 2
> 2 4
> 1 3
> ```
> 根据题意，为了尽早的吃到 $1$ 号菜肴，第一步必须是先做 $3$ 号菜肴，**而不是用最小堆局部贪心**，导致先做 $2$ 号菜肴。
>
> **本质**：字典序最小的方案，其中 $1$ 并不一定最靠前。
>
> 因为字典序是贪心的，如果当前位可以小就尽可能的小，但是其可以解锁的菜肴不一定是最小的。




正解：反图 + 大根堆求字典序最大的方案，答案就是其逆序。

原因：大的数尽量靠后，尽可能的让其它小的数靠前。


```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> ind(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[v].emplace_back(u);
        ind[u]++;
    }
    vector<int> seq;
    auto topo = [&]() {
        priority_queue<int> q;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0) {
                q.emplace(i);
            }
        }
        while (!q.empty()) {
            auto u = q.top();
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
    if (seq.size() < n) {
        cout << "Impossible!\n";
        return;
    }

    for (int i = seq.size() - 1; i >= 0; i--) {
        cout << seq[i] + 1 << ' ';
    }
    cout << '\n';
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
```

## LG P4017 最大食物链计数

[P4017 最大食物链计数](https://www.luogu.com.cn/problem/P4017) 

经典 DP 求图上路径条数：

$f(i)$：表示从**某个**入度为 $0$ 的点到点 $i$ 的路径条数。

转移：$f(v) \leftarrow f(v) + f(u)$ ( $u \rightarrow v$ )

初始状态 $f(u)_{ind(u) = 0} = 1$

答案：$\sum_{outd(u) = 0} f(u)$


## LG P1038 [NOIP2003 提高组] 神经网络

[P1038 [NOIP2003 提高组] 神经网络](https://www.luogu.com.cn/problem/P1038) 




```cpp

```


## LG P2597 [ZJOI2012] 灾难

[P2597 [ZJOI2012] 灾难](https://www.luogu.com.cn/problem/P2597) 

$f(u)$：表示点 $u$ 的灾难值。

转移：

$f(u) = \sum\limits_{(u, v) \in G, \, ind(v) = 1} (f(v) + 1)$

$f(u)$ 等于其所有后继节点的集合中，入度为 $1$ 的点 $v$ 的灾难值 $f(v)$ 的和加 $1$。


```cpp

```



## LG P4934 礼物

[P4934 礼物](https://www.luogu.com.cn/problem/P4934) 

```cpp

```

