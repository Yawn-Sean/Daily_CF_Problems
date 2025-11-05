#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9 + 7;
const int N = 3e5 + 10;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1), b;
    for(int i =1 ;i <= n; i ++)cin >> a[i];
    int ans = 1e18, tmp = 0;
    b = a;
    for(int i = 2; i <= n; i ++){
        if(i&1){
            if(b[i] >= b[i-1])tmp += b[i] - b[i-1] + 1, b[i] = b[i-1] - 1;
        }
        else{
            if(b[i] <= b[i-1])tmp += b[i-1] - b[i] + 1, b[i] = b[i-1] + 1;
        }
    }
    ans = min(ans, tmp);
    tmp = 0;
    b = a;
    for(int i = 2; i <= n; i ++){
        if((i&1) == 0){
            if(b[i] >= b[i-1])tmp += b[i] - b[i-1] + 1, b[i] = b[i-1] - 1;
        }
        else{
            if(b[i] <= b[i-1])tmp += b[i-1] - b[i] + 1, b[i] = b[i-1] + 1;
        }
    }
    ans = min(ans, tmp);
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
