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