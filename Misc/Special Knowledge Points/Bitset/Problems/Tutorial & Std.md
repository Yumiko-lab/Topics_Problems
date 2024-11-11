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

首先 $f$ 数组首先优化掉第一维，然后第二位用 bitset 代替。


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