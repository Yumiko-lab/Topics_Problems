#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 2, MOD = 1'000'000'007;

i64 n;
int res[N][N] = {1, 1}; // {f[n], f[n + 1]}
int A[N][N] = {
    {0, 1},
    {1, 1}
};

void mul(int c[][N], int a[][N], int b[][N]) { // c = a * b
    static int temp[N][N] {};
    memset(temp, 0, sizeof temp);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                temp[i][j] = (temp[i][j] + 1LL * a[i][k] * b[k][j] % MOD) % MOD;
            }
        }
    }
    memcpy(c, temp, sizeof temp);
}

void power() {
    i64 k = n - 1;
    while (k) {
        if (k & 1) {
            mul(res, res, A);
        }
        mul(A, A, A);
        k >>= 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    power();

    cout << res[0][0] << '\n';

    return 0;
}