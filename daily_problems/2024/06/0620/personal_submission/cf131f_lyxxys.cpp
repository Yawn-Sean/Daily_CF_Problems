#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 505, inf = 0x3f3f3f3f, mod = 1e9+7;

bool istar[N][N];
int g[N][N], cnt[N][N];
// cnt[i][j] 表示前i行第j列算上 左右的白像素有多少个合法星星

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j){
            char c;
            cin >> c;
            g[i][j] = c-'0';
        }

    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j){
            if (i==1||i==n||j==1||j==m||g[i][j]==0) continue;
            if (g[i+1][j]==1&&g[i-1][j]==1&&g[i][j-1]==1&&g[i][j+1]==1)
                istar[i][j] = true;
            else istar[i][j] = false;
        }
    //预处理cnt
    for (int j = 2; j <= m-1; ++ j){
        for (int i = 2; i <= n-1; ++ i)
            cnt[i][j] = cnt[i-1][j] + istar[i][j];
    }

    ll res = 0;
    // O(n^2)上下边界枚举 套 双指针O(m)统计
    for (int len = 3; len <= n; ++ len){
        for (int up = 1; up+len-1 <= n; ++ up){
            int down = up+len-1;
            //不要边界
            int sum = cnt[down-1][2] - cnt[up][2];
            for (int l = 1, r = min(3,m); l <= m-2; ++ l){
                while (r+1 <= m && sum < k) sum += cnt[down-1][r]-cnt[up][r], ++ r;
                if (sum >= k) res += m-r+1;
                else break;
                sum -= cnt[down-1][l+1] - cnt[up][l+1];
            }
        }
    }

    cout << res << "\n";
}
