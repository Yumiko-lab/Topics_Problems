
## CF1328D


> Description：
> 
> 给定一个有 $n$ 个点的环，第 $i$ 个点的类型是 $a_i$，现在需要给每个点进行染色，要求**相邻且类型不同的点的颜色不同**，且所用的颜色数最小，输出一种染色方案。
> - $3 \le n \le 2 \times 10^5$ 



随便手玩一下可以发现，使用的颜色数量不会超过 $3$。

分类讨论：

1. 所有点类型都相同 $\implies$ $1$ 
2. 相邻的点的类型都不同：
   1. 若 $n$ 是偶数，$1, 2$ 交替，答案是 $2$。
   2. $n$ 是奇数，$1, 2$ 交替，且最后一个小球染 $3$，答案是 $3$。
3. **同时存在**相邻的球种类相同和不同的情况：
   1. $n$ 是偶数，$1, 2$ 交替，答案是 $2$。
   2. $n$ 是奇数，从一个相邻相同的球对中的一个小球开始染色，$1, 2$ 交替扩展一圈，最终回到另一个小球，答案是 $2$。


写代码的时候需要注意数组开头和结尾也是相邻。

> 容易陷入的误区：种类相同的球的颜色不一定全都要相同。

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    array<bool, 2> has{};
    for (int i = 0; i < n; i++) {
        if (t[i] == t[(i + 1) % n]) {
            has[0] = true;
        } else {
            has[1] = true;
        }
    }
    if (!has[1]) {
        cout << 1 << '\n';
        for (int i = 0; i < n; i++) {
            cout << 1 << " \n"[i == n - 1];
        }
    } else if (!has[0]) {
        if (n % 2) {
            cout << 3 << '\n';
            for (int i = 0; i < n - 1; i++) {
                cout << (i % 2 + 1) << " \n"[i == n - 1];
            }
            cout << 3 << '\n';
        } else {
            cout << 2 << '\n';
            for (int i = 0; i < n; i++) {
                cout << (i % 2 + 1) << " \n"[i == n - 1];
            }
        }
    } else {
        if (n % 2) {
            cout << 2 << '\n';
            vector<int> col(n);
            for (int i = 0; i < n; i++) {
                if (t[i] == t[(i + 1) % n]) {
                    col[i] = col[(i + 1) % n] = 1;
                    int j = (i - 1 + n) % n, w = 2;
                    while (!col[j]) {
                        col[j] = w;
                        j = (j - 1 + n) % n;
                        w = 3 - w;
                    }
                    break;
                }
            }
            for (int i = 0; i < n; i++) {
                cout << col[i] << " \n"[i == n - 1];
            }
        } else {
            cout << 2 << '\n';
            for (int i = 0; i < n; i++) {
                cout << (i % 2 + 1) << ' ';
            }
            cout << '\n';
        }
    }
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

/*

1
3
1 2 1

*/
```


