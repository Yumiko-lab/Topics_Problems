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