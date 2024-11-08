# Sieve

## CF546D

第一次看到题目我会想到 —— [P10495 阶乘分解](https://www.luogu.com.cn/problem/P10495) 

但是此题是对多个数进行 $1 \sim 5e6$ 所有数进行阶乘分解，显然超时，进一步才想到可以用线性筛递推。

> 性质：$n!$ 的质因子个数等价于 $1 \sim n$ 中所有数字的质因子的个数相加。

$f(i)$：表示数 $i$ 的质因子的数量

最小质因子 $p$ 筛其他数的时候：$f(i \times p) = f(i) + 1$



( push DP )

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> minp, primes;
vector<int> f;

void sieve(int n) {
    f.assign(n + 1, 0);
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            f[i] = 1;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            f[i * p] = f[i] + 1;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << f[a] - f[b] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(5E6);

    for (int i = 1; i <= 5E6; i++) {
        f[i] += f[i - 1];
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
```