#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7, inf = 1e9;

void solve(){            
    int n, k;
    cin >> n >> k;
    vector <vector<int>> g(n+1, vector<int>(n+1,inf)), f(n+1, vector<int>(n+1)), fs(n+1, vector<int>(n+1,inf));
    // fs[i][j] 表示走到第 i 行 j 列 让前缀都为 'a' 的最小修改次数
    // f[i][j] 表示 是否是字典序最小的路径经过的
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            char ch;
            cin >> ch;
            g[i][j] = ch-'a';
        }
    }

    // 求 fs[i][j]
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            if (i == 1 && j == 1) fs[i][j] = g[i][j]!=0;
            else fs[i][j] = min(fs[i-1][j], fs[i][j-1]) + (g[i][j] != 0);
            if (fs[i][j] <= k) g[i][j] = 0;
        }
    }
    // 求 f[i][j]
    f[1][1] = 1;
    for (int len = 2; len <= 2*n-1; ++ len){
        int mins = inf;
        for (int i = max(1,len-n+1); i <= min(len,n); ++ i){
            int j = len-i+1;
            if (f[i-1][j] || f[i][j-1]) mins = min(mins, g[i][j]);
        }
        for (int i = max(1,len-n+1); i <= min(len,n); ++ i){
            int j = len-i+1;
            if (f[i-1][j] || f[i][j-1]) f[i][j] = g[i][j] == mins;
        }
    }

    // 从 终点到起点 记录答案
    string res;
    {
        int i = n, j = n;
        while (i != 1 || j != 1){
            res += char(g[i][j]+'a');
            if (f[i-1][j]) -- i;
            else -- j;
        }
        res += char(g[1][1]+'a');
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
}
