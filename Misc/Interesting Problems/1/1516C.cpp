#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    array<int, 2> even{11, -1}; // Smallest number of power of 2
    int odd = -1; // position of any odd element 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if (a[i] % 2) {
            odd = i;
        } else {
            int t = a[i], s = 0;
            while (t % 2 == 0) {
                t /= 2;
                s++;
            }
            if (s < even[0]) {
                even = {s, i};
            }
        }
    }
    if (sum % 2) {
        return cout << 0, 0;
    }

    vector<int> f(sum / 2 + 1);
    f[0] = 1;
    for (auto x : a) {
        for (int i = sum / 2; i >= x; i--) {
            f[i] |= f[i - x];
        }
    }

    if (!f[sum / 2]) {
        return cout << 0, 0;
    }

    if (odd != -1) {
        cout << 1 << '\n';
        return cout << odd + 1, 0;
    }

    cout << 1 << '\n';
    cout << even[1] + 1 << '\n';

    return 0;
}