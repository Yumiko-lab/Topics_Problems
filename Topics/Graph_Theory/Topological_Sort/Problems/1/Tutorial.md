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
        adj[v].emplace_back(u); // 反图: u -> v  =>  v -> u
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