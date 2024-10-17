# Regular Bracket Sequence

Regular Bracket Sequence：括号序列


## CF5C - Longest Regular Bracket Sequence




```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);

    stack<int> stk;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else if (!stk.empty()) {
            int t = stk.top();
            stk.pop();
            a[t] = a[i] = 1;
        }
    }

    array<int, 2> mx{0, 1};
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            int j = i;
            while (j < n && a[j] == a[i]) {
                j++;
            }
            if (j - i > mx[0]) {
                mx = {j - i, 1};
            } else if (j - i == mx[0]) {
                mx[1]++;
            }
            i = j;
        }
    }
    
    cout << mx[0] << ' ' << mx[1] << '\n';
    
    return 0;
}
```


- 另一种思路：

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    auto calc = [&](auto s) -> array<int, 2> {
        array<int, 2> ans{0, 1};
        int now = 0, cnt = 0;
        for (auto c : s) {
            now += (c == '(' ? 1 : -1);
            if (now < 0) {
                now = cnt = 0;
            } else if (now == 0) {
                cnt++;
                if (cnt > ans[0]) {
                    ans = {cnt, 1};
                } else if (cnt == ans[0]) {
                    ans[1]++;
                }
            } else {
                cnt++;
            }
        }
        return ans;
    };

    auto mx1 = calc(s);
    for (auto &c : s) {
        if (c == '(') {
            c = ')';
        } else {
            c = '(';
        }
    }
    auto mx2 = calc(string(s.rbegin(), s.rend()));

    auto mx = max(mx1, mx2);
    cout << mx[0] << ' ' << mx[1] << '\n';
    
    return 0;
}

/*

(()()
()())

RBS: 

1. s[1 .. len] >= 0
2. s[len] == 0

*/
```


