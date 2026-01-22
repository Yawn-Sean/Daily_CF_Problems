#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;
void solve()
{
    int n;
    cin >> n;   
    vector<int> a(n+1), dp1(n+1), dp2(n+1);
    for(int i = 1; i <= n; i ++)cin >> a[i];
    int pos = -1;
    for(int i = 1; i <= n; i ++){
        if(a[i] == -1)dp1[i] = dp1[i-1] + 1;
        else{
            if(pos != -1){
                if(a[i] <= a[pos])dp1[i] = dp1[i-1] + 1;
                else dp1[i] = i - pos;
            }
            else dp1[i] = dp1[i-1] + 1;
            pos = i;
        }
    }
    pos = -1;
    for(int i = n; i >= 1; i --){
        if(a[i] == -1)dp2[i] = dp2[i+1] + 1;
        else{
            if(pos != -1){
                if(a[i] <= a[pos])dp2[i] = dp2[i+1] + 1;
                else dp2[i] = pos - i;
            }
            else dp2[i] = dp2[i+1] + 1;
            pos = i;
        }
    }
    for(int k = 3; k <= n;k ++){
        int ok = 1;
        for(int i = 1; i <= n; i += k){
            int j = min(i+k-1, n);
            if(dp1[j] + dp2[i] < j-i+2 || j-i+1 < 3 || dp1[j] < 2 || dp2[i] < 2)ok = 0;
        
        }
        if(ok){
            
            cout << "Y\n";
            return ;
        }
    }
    cout << "N\n";
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
