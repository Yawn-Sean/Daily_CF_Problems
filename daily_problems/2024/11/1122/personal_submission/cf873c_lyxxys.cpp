#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, T b){  // 模板类无法处理 long double 问题
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n, vector<int>(m)), col(n+1, vector<int>(m));
    
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            cin >> g[i][j];
            col[i+1][j] = col[i][j] + g[i][j];
        }
    }

    int ans1 = 0, ans2 = 0;
    for (int j = 0; j < m; ++ j){
        int val = 0, cost = 0;
        for (int i = 1; i <= n-k+1; ++ i){
            int x = col[i+k-1][j] - col[i-1][j];
            if (x > val){
                val = x;
                cost = col[i-1][j];
            }
        }
        ans1 += val, ans2 += cost;
    }

    cout << ans1 << " " << ans2 << "\n";
}
