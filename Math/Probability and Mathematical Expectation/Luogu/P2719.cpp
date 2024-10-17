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