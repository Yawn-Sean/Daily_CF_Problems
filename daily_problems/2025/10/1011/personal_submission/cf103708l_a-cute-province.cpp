#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+2), l(n+1), r(n+1), f(n+1), sum1(n+1), sum2(n+1);
    for(int i = 1; i <=n ; i ++)cin >> a[i];
    for(int i = 1; i <=n; i ++)sum1[i] = sum1[i-1] + a[i], sum1[i] %=mod;
    for(int i = 1; i <=n; i ++)sum2[i] = sum2[i-1] + sum1[i], sum2[i] %= mod;
    stack<int> stk = {}; stk.push(0);
    a[0] = a[n+1] = 1e9 + 1;
    for(int i = 1; i <= n; i++){
        while(!stk.empty() && a[stk.top()] <= a[i])stk.pop();
        l[i] = stk.top();
        stk.push(i);
    }
    stk = {}; stk.push(n+1);
    for(int i = n; i >= 1; i --){
        while(!stk.empty() && a[stk.top()] <= a[i])stk.pop();
        r[i] = stk.top();
        stk.push(i);
    }
    int ans = 0;
    for(int i = 1; i <=n; i ++){
        f[i] = (sum2[r[i]-1] - sum2[i-1] + mod)%mod * (i - l[i])%mod - (sum2[i-1] - sum2[max(l[i]-1, 0ll)] + mod)%mod * (r[i] - i)%mod;
        //cout << f[i] <<'\n';
        ans += (f[i] +mod)%mod;
        ans %= mod;
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
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
