#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 2e5 + 10;
void solve()
{
    int n, K;
    cin >> n >> K;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    for(int i = 1; i<= n; i++){
        for(int j = i; j <= n;j ++)dp[i][j] = 1e18;
    }
    for(int l = 2; l <= n;l  ++){
        for(int i = 1;i+l-1 <= n; i ++){
            int j = i + l - 1;
            int mi = 1e18;
            if(j-i+1 >= 2 && abs(a[i]-a[j])<=K)
            mi = min(mi, dp[i+1][j-1] + 1);
            if(j-i+1>= 3 && abs(a[i]-a[j])<=K){
                int up = max(a[i], a[j]), down = min(a[i], a[j]);
                for(int k = i + 1; k < j; k ++){
                    if(max(up, a[k]) - min(down, a[k]) <= K)
                    mi = min(mi, dp[i+1][k-1] + dp[k+1][j-1] + 1);
                }
            }
            for(int k = i + 1; k +1 < j; k ++){
                mi = min(mi, dp[i][k] + dp[k+1][j]);
            }
            
            dp[i][j] = mi;
            //cout << mi << '\n';
        }
    }

    vector<PII> ddp(n+1);
    ddp[0] = {0, 0};
    for(int i = 1; i <= n; i ++){
    	ddp[i] = {i, 0};
        for(int l = 1; l < i; l ++){
            for(int r = l+1; r <= i; r ++){
            	if(dp[l][r] == 1e18)continue;
                if(ddp[l-1].x + i-r < ddp[i].x){
                    ddp[i] = make_pair(ddp[l-1].x + i-r, ddp[l-1].y + dp[l][r]);
                }
                else if(ddp[l-1].x + i-r == ddp[i].x){
                    ddp[i].y = min(ddp[i].y, ddp[l-1].y + dp[l][r]);
                }
            }
        }
        //cout << ddp[i].x << ' ' << ddp[i].y << '\n';
    }
    cout << ddp[n].x << ' ' << ddp[n].y << '\n';
}
signed cute_prov0nce()
{   
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);     
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //t = 1; 
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
