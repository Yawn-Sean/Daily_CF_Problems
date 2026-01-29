#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 1e9 + 7;
const int N = 1e3 + 10;
int dp[N][12*N];
void solve()
{   
    int n, k;
    cin >> n >> k;
    k = min(k, 12*n);
    vector<int> b(n+1), c(n+1), f(N, 1e18);
    f[1] = 0;
    for(int i = 1; i <= n; i ++)cin >> b[i];
    for(int i = 1; i <= n; i ++)cin >> c[i];   
    for(int i = 1; i < N; i ++){
        for(int z = 1; z <= i; z++){
            if(i + i/z < N)
            f[i + i/z] =  min(f[i + i/z], f[i] + 1);
        }
    }     
    //cout << *max_element(f.begin()+1, f.end()) << '\n';
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= k;j ++){
            if(j >= f[b[i]])
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-f[b[i]]] + c[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][k] << '\n';
}
signed cute_prov0nce()
{   
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
