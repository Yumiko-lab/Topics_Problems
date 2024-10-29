#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2, MOD = 1'000'000'007;

int n;
int res[N] = {1, 1}; // {f[n], f[n + 1]}
int A[N][N] = {
    {0, 1},
    {1, 1}
};

void mul(int c[][N], int a[][N], int b[][N]) {
    static int temp[N][N] {};
    memset(temp, 0, sizeof temp);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                temp[i][j] = (temp[i][j] + 1LL * a[i][k] + b[k][j] % MOD) % MOD;
            }
        }
    }
    memcpy(c, temp, sizeof temp);
}

void mul(int c[N], int a[N], int b[][N]) {
    static int temp[N] {};
    memset(temp, 0, sizeof temp);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i] = (temp[i] + 1LL * a[j] * b[j][i] % MOD) % MOD;
        }
    }
    memcpy(c, temp, sizeof temp);
}

void power() {
    int k = n - 1;
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

    cout << res[0] << '\n';

    return 0;
}