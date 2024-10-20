

# 概率与数学期望





## 绿豆蛙的归宿



[P4316 绿豆蛙的归宿](https://www.luogu.com.cn/problem/P4316) 



```cpp
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(2);

    int n, m;
    cin >> n >> m;
    vector<vector<PII>> adj(n);
    vector<double> f(n, -1);
    vector<int> dout(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w); // u -> v
        dout[u]++;
    }
    
    auto dp = [&](auto self, int u) -> double {
        if (f[u] >= 0) { // Floating point comparison (not f[u] != -1)
            return f[u];
        }
        f[u] = 0;
        for (auto [v, w] : adj[u]) {
            f[u] += (self(self, v) + w) / dout[u];
        }
        return f[u];
    };
    
    cout << dp(dp, 0) << '\n';
    
    return 0;

}
```





## 换教室



[P1850 [NOIP2016 提高组] 换教室](https://www.luogu.com.cn/problem/P1850) 



```cpp
```





## 搞笑世界杯



[P2719 搞笑世界杯](https://www.luogu.com.cn/problem/P2719) 



$f(i, j)$：表示售票人员手中还剩 $i$ 张 $A$，和 $j$ 张 $B$ 时，最后两人买到同一张票的概率。



初始状态：$\sum_{i = 1}^n f(i, 0) = f(0, i) = 1$ 

答案：$f(n, n)$ 



转移：
$$
f(i, j) = f(i - 1, j) \times 0.5 + f(i, j - 1) \times 0.5
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(4);

    int n;
    cin >> n;
    n /= 2;
    vector<vector<double>> f(n + 1, vector<double>(n + 1));

    for (int i = 2; i <= n; i++) {
        f[i][0] = f[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = (f[i][j - 1] + f[i - 1][j]) / 2;
        }
    }

    cout << f[n][n] << '\n';

    return 0;
}
```





## 单选错位



[P1297 [国家集训队] 单选错位](https://www.luogu.com.cn/problem/P1297) 





分类讨论：



1. $a_i = a_{i + 1}$：
2. $a_i > a_{i + 1}$：
3. $a_i < a_{i + 1}$：



没看懂分类讨论？？





综上所述，答案就是 $\sum_{i = 1}^n \dfrac 1{\max(a_i, a_{i + 1})}$。







```cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 100000001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(3);

    int n, A, B, C;
    cin >> n >> A >> B >> C;
    vector<int> a(n + 1);
    cin >> a[1];
    for (int i = 2; i <= n; i++) {
        a[i] = (1LL * a[i - 1] * A % MOD + B) % MOD;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = a[i] % C + 1;
    }

    double ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1.0 / max(a[i], a[i % n + 1]);
    }
    cout << ans << '\n';

    return 0;
}
```





## WJMZBMR打osu! / Easy



[P1365 WJMZBMR打osu! / Easy](https://www.luogu.com.cn/problem/P1365) 



$f(i)$：表示以第 $i$ 个字符结尾的期望得分。



转移：

记期望连续的 $\rm o$ 的个数为 $\rm len$，

1. $s_i = \rm o$：$f(i) = f(i - 1) + [({\rm len} + 1)^2 - {\rm len}^2] = f(i - 1) + 2 \times {\rm len} + 1$，同时更新 ${\rm len} \leftarrow {\rm len} + 1$。
2. $s_i = \rm x$：$f(i) = f(i - 1)$，${\rm len} \leftarrow 0$。
3. $s_i =  \, ?$：$f(i) = f(i - 1) + \dfrac {[({\rm len} + 1)^2 - {\rm len}^2]  + 0}2 = f(i - 1) + {\rm len} + 0.5$，${\rm len} \leftarrow \dfrac {{\rm len} + 1 + 0}2 = \dfrac {{\rm len} + 1}2$。





```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(4);

    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;
    vector<double> f(n + 1);
    double len = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'o') {
            f[i] = f[i - 1] + 2 * len + 1;
            len++;
        } else if (s[i] == 'x') {
            f[i] = f[i - 1];
            len = 0;
        } else { // s[i] == '?'
            f[i] = f[i - 1] + len + 0.5;
            len = (len + 1) / 2;
        }
    }

    cout << f[n] << '\n';


    return 0;
}
```









## OSU!



[P1654 OSU!](https://www.luogu.com.cn/problem/P1654) 



```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(1);

    int n;
    cin >> n;
    vector<double> f(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<double> x1(n + 1), x2(n + 1);
    for (int i = 1; i <= n; i++) {
        x1[i] = (x1[i - 1] + 1) * p[i];
        x2[i] = (x2[i - 1] + 2 * x2[i - 1] + 1) * p[i];
        f[i] = f[i - 1] + (3 * x2[i - 1] + 3 * x1[i - 1] + 1) * p[i];
    }

    cout << f[n] << '\n';

    return 0;
}
```







## 非诚勿扰



[P6089 [JSOI2015] 非诚勿扰](https://www.luogu.com.cn/problem/P6089) 





```cpp
```



