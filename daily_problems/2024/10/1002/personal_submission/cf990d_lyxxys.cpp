#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    if (a != 1 && b != 1) return cout << "NO\n", void();
    vector <vector<int>> g(n, vector<int>(n));
    if (a == 1 && b == 1){
        if (n == 3 || n == 2) return cout << "NO\n", void();
        for (int i = 0; i < n-1; ++ i){
            g[i][i+1] = g[i+1][i] = 1;
        }
    } else {
        int siz = n - max(a, b);
        for (int i = 0; i < siz; ++ i){
            g[i][i+1] = g[i+1][i] = 1;
        }
        if (a==1){
            for (int i = 0; i < n; ++ i){
                for (int j = 0; j < n; ++ j){
                    if (i==j) continue;
                    g[i][j] = g[i][j]^1;
                }
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            cout << g[i][j];
        }
        cout << "\n";
    }
}
