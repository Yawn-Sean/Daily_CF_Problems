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
const int N = 1e4 + 10;
int dp[N];
void solve()
{
    int n, B;
    cin >> n >> B;
    vector<int> a(n+1), b(n+1);
    vector<PII> ve;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++)cin >> b[i];
    for(int i = 1; i <= n;i  ++)ve.emplace_back(a[i], b[i]);
    sort(ve.begin(), ve.end(), [&](auto i, auto j){
        return i.y > j.y;
    });
    for(int i = 1; i <= n; i ++){
        for(int j = i; j >= 1; j --){
            if(i-1 >= j)dp[j] = min(dp[j-1] + ve[i-1].x + (j-1)*ve[i-1].y, dp[j]);
            else dp[j] = dp[j-1] + ve[i-1].x + (j-1)*ve[i-1].y;
            //cout << dp[j] << ' ';
        }
        //cout << '\n';
    }    
    for(int j = n; j >= 0; j --){
        if(dp[j] <= B){
            cout << j << ' ' << dp[j] << '\n';
            return ;
        }
    }
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
