#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 998244353;
const int N = 2e5 + 10;
/*
    对于竞标赛图，如果它是 DAG，那么它有且仅有一个拓扑序。
*/
int qpow(int a,int b){
    int res =1;
    while(b){
        if(b&1)res = res * a %mod;
        b >>= 1;
        a = a * a %mod;
    }
    return res;
}
int inv(int x){
    return qpow(x, mod-2)%mod;
}
void solve()
{   
    int n, a, b;
    cin >> n >> a >> b;
    int P = a * inv(b)%mod, Q = (1 - P + mod)%mod;
    int res = 1, s = 1, cur = 1;
    for(int i = 2; i <= n; i ++){
        cur *= Q;
        cur %=mod;
        s = cur + P * s %mod;
        s %= mod;
        res = res * s;
        res %= mod;
    }
    cout << res << '\n';
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
