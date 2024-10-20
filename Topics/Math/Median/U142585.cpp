#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template <typename T>
struct Fenwick {
    int n;
    vector<T> tr;
    
    Fenwick(int n) : n(n), tr(n + 1, 0) {}
	
    int lowbit(int x) {
        return x & -x;
    }
    
    void add(int x, const T &v) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tr[i] += v;
        }
    }
    
    T query(int x) {
        T res {};
        for (int i = x; i; i -= lowbit(i)) {
            res += tr[i];
        }
        return res;
    }
    
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto check = [&](auto x) {
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + (a[i] >= x ? 1 : -1);
        }
        for (int i = 0; i <= n; i++) {
            s[i] += n + 1;
        }
        Fenwick<int> bit(2 * n + 5);
        bit.add(s[0], 1);
        i64 sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += 2 * bit.query(s[i]) - i; // bit.query(s[i]) - (i - bit.query(s[i]))
            bit.add(s[i], 1);
        }
        return sum >= 0;
    };

    int lo = 1, hi = 1e9;
    while (lo < hi) {
        int mi = (lo + hi + 1) >> 1;
        if (check(mi)) {
            lo = mi;
        } else {
            hi = mi - 1;
        }
    }

    cout << hi << '\n';

    return 0;   
}