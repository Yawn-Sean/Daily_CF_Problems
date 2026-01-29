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
const int N = 5e6 + 10;
int f[N];
int qpow(int a, int b){
    int res = 1;
    while(b){
        if(b & 1)res = res * a %mod;
        b >>= 1;
        a = a * a %mod;
    }
    return res;
}
int inv(int x){
    return qpow(x, mod-2) %mod;
}
void solve()
{   
    int b, g, x, y;
    cin >> b >> g >> x >> y;
    if(x + y > g){
        cout << 0 << '\n';
        return ;
    }
    cout << (f[b+g] * inv(f[g])%mod * inv(f[b])%mod - f[x+y-1+b] * inv(f[b])%mod * inv(f[x+y-1])%mod + mod)%mod << '\n';
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
    f[0] = 1;
    for(int i =1 ; i < N; i ++)f[i] = f[i-1] * i %mod;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
