#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int p;
        while (cin >> p, p) {
            adj[p].emplace_back(i);
        }
        
    }

    return 0;
}