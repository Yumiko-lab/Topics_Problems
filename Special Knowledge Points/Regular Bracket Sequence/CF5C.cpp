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