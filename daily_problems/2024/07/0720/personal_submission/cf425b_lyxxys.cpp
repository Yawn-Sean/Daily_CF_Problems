#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 105, mod = 1070777777, inf = 1e9;
/*
    行为n，列为m，最大操作次数为k，若一行确定，其他所有行也能够用相邻行的相反和相同递推，以此求最小成本
    分情况调整时间复杂度
        若 n > k:
            一定有一行没有任何改变，枚举这一行
        若 n <= k:
            由于n很小，枚举第一列的初始状态
*/
int g[N][N];
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            cin >> g[i][j];
        }
    }

    int res = inf;
    if (n <= k){
        // 调整每一列
        for (int s = 0; s < 1<<n; ++ s){
            int ans = 0;
            for (int j = 0; j < m; ++ j){
                int cnt = 0;
                for (int  i = 0; i < n; ++ i){
                    cnt += g[i][j] == (s>>i &1);
                }
                ans += min(cnt, n-cnt);
            }
            res = min(res, ans);
        }
    } else {
        // 调整每一行
        for (int i = 0; i < n; ++ i){
            int ans = 0;
            for (int j = 0; j < n; ++ j){
                if (i == j) continue;
                int cnt = 0;
                for (int p = 0; p < m; ++ p){
                    cnt += g[i][p] == g[j][p];
                }
                ans += min(cnt, m-cnt);
            }
            res = min(res, ans);
        }
    }
    cout << (res > k ? -1 : res) << "\n";
}
