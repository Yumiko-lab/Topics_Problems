#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> ans(3, vector<int>(n));
    vector<vector<int>> pos(3, vector<int>(n + 1));
    iota(ans[0].begin(), ans[0].end(), 1);
    ans[1] = ans[0];
    for (int i = 0; i < n; i += 2) {
        swap(ans[1][i], ans[1][i + 1]);
    }

    ans[2] = ans[0];
    swap(ans[2][0], ans[2][n - 1]);
    for (int i = 1; i < n - 1; i += 2) {
        swap(ans[2][i], ans[2][i + 1]);
    }

    for (int t = 0; t < 3; t++) {
        for (int i = 0; i < n; i++) {
            pos[t][ans[t][i]] = i;
        }
    }

    cout << '\n';

    for (auto t : {0, 1, 2}) {
        cout << t << " : ";
        for (auto x : ans[t]) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    int id = 0, f = 0, p = 0;

    auto print = [&]() {
        for (int i = 0; i < n; i++) {
            cout << ans[id][(f + i) % n] << ' ';
        }
        cout << '\n';
    };

    
    print();

    while (q--) {
        int op, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
            f = (f - x + n) % n;
            p ^= (abs(x) % 2);
        } else {
            f = (f + 1) % n;
            // if (f % 2) {
            //     f = (f - 1) % n;
            // } else {
            //     f = (f + 1) % n;
            // }
            int pre = id;
            if (p % 2) { // 2
                if (id == 0) {
                    id = 2;
                } else if (id == 1) {
                    id = 2;
                } else {
                    id = 0;
                    p = 0;
                }
            } else { // 1
                if (id == 0) {
                    id = 1;
                } else if (id == 1) {
                    id = 0;
                    p = 0;
                } else {
                    id = 1;
                }
            }
            f = pos[id][ans[pre][f]];
        }
        cout << "id : " << id << ", f : " << f << ", " << "p : " << p << '\n';
        print();
    }

    cout << '\n';

    print();

    for (int i = 0; i < n; i++) {
        cout << ans[id][(f + i) % n] << ' ';
    }
    cout << '\n';

    return 0;
}

/*

4 2
1 1
2

4 4
1 -1 
2 
1 -1 
2 

6 4
2 
1 3 
2 
2 


4 4
2 
1 -3 
2 
2 

*/