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
const int N = 7000 + 10;
int sum[N][N], f[N][N], a[N];
void solve()
{   
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)cin >> a[i];
    sort(a+1, a+1+n);
    int ans = (n + n*(n-1)/2)%mod;
    for(int j = 3; j <= n; j ++){
        int k = 1, i = j-1;
        for(;i > 1; i --){
            while(k < i && a[k] + a[i] <= a[j])k++;
            if(a[k] + a[i] > a[j] || k >= i)k--;
            if(k == 0)continue;
            if(a[k] + a[i] <= a[j]){
                f[i][j] += sum[k][i] + k;
                f[i][j] %= mod;
                
                ans += f[i][j];
                ans %= mod;
            }
        }

        for(int i = 1; i < j; i ++){
            sum[i][j] += sum[i-1][j] + f[i][j], sum[i][j] %= mod;
           
        }
    }
    
    cout << ans << '\n';
   

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
