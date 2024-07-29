#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 4e5+10, mod = 1e9 + 7, inf = 1e9;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> g(2*n+1, vector<int>(2*n+1)), Sum(2*n+1, vector<int>(2*n+1));

    int all = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            char ch;
            cin >> ch;
            g[i][j] = ch-'0';
            all += g[i][j];
            g[i+n][j+n] = g[i+n][j] = g[i][j+n] = g[i][j];
        }
    }
    for (int i = 1; i <= 2*n; ++ i){
        for (int j = 1; j <= 2*n; ++ j){
            Sum[i][j] = Sum[i-1][j-1] + g[i][j];
        }
    }
    int res = 1e9;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            int x = Sum[i+n-1][j+n-1]-Sum[i-1][j-1];
            res = min(res, (n-x)+(all-x));
        }
    }

    cout << res << "\n";
}
