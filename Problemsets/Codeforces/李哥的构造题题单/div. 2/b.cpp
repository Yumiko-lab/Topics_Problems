#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        a[i][i] = b[i];
    }
    // a[i][j] in [0, n - 1]

    

    return 0;
}