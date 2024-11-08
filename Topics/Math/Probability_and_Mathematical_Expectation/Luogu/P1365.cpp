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
            f[i] = f[i - 1] + len + 0.5; // (2 * len + 1) / 2  =>  len + 0.5
            len = (len + 1) / 2; // len = (len + 1 + 0) / 2
        }
    }

    cout << f[n] << '\n';


    return 0;
}