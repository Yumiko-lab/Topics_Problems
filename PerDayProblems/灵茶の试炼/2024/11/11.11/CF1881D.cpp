#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> minp, primes;

void sieve(int n) {
    primes.clear();
    minp.assign(n + 1, 0);
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.emplace_back(i);
        }
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (minp[i] == p) {
                break;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    map<int, int> fact; // factor
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x > 1) {
            int f = minp[x];
            x /= f;
            fact[f]++;
        }
    }
    for (auto [x, y] : fact) {
        if (y % n != 0) {
            return void(cout << "NO\n");
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(1E6);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}