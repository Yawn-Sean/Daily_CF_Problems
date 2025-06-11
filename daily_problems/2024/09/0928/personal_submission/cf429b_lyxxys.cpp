#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2005000, inf = 0x3f3f3f3f, P = 998244353;

void solve(){
    int n, m;
    cin >> n >> m;
    vector <vector<int>> og(n+1, vector<int>(m+1));
    vector <vector<ll>> f1(n+2, vector<ll>(m+2)), f2(n+2, vector<ll>(m+2));
    vector <vector<ll>> g1(n+2, vector<ll>(m+2)), g2(n+2, vector<ll>(m+2));
    // 预处理 A、B 的 正向dp 和 反向dp
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            cin >> og[i][j];
        }
    }

    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            f1[i][j] = max(f1[i-1][j], f1[i][j-1]) + og[i][j];  // 上边和左边
        }
    }
    for (int i = n; i >= 1; -- i){
        for (int j = m; j >= 1; -- j){
            f2[i][j] = max(f2[i+1][j], f2[i][j+1]) + og[i][j];  // 下边和右边
        }
    }
    for (int i = n; i >= 1; -- i){
        for (int j = 1; j <= m; ++ j){
            g1[i][j] = max(g1[i+1][j], g1[i][j-1]) + og[i][j];  // 下边和左边
        }
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = m; j >= 1; -- j){
            g2[i][j] = max(g2[i-1][j], g2[i][j+1]) + og[i][j];  // 上边和右边
        }
    }

    auto find1 = [&](int i, int j)->long long{
        return f1[i][j-1]+f2[i][j+1] + g1[i+1][j]+g2[i-1][j];
    };  // 转移方向：A从左 B从下
    auto find2 = [&](int i, int j)->long long{
        return g1[i][j-1]+g2[i][j+1] + f1[i-1][j]+f2[i+1][j];
    };  // 转移方向：B从左 A从上
    auto find3 = [&](int i, int j)->long long{
        return f1[i-1][j]+g1[i+1][j] + max(f2[i][j+1], g2[i][j+1]);
    };  // 上下对冲

    long long res = 0;

    for (int i = 2; i < n; ++ i){
        for (int j = 2; j < m; ++ j){
            long long t = max({find1(i, j), find2(i, j), find3(i, j)});
            res = max(res, t);
        }
    }

    cout << res << "\n";
}
 
