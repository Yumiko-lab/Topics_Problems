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