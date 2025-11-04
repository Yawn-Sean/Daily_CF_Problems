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
const int N = 1e6 + 10;
int ans[N], f[N];
int qpow(int a, int b){
    int res = 1;
    while(b){
        if(b&1)res = res * a%mod;
        b >>= 1;
        a = a * a%mod;
    }
    return res;
}
int inv(int x){
    return qpow(x, mod-2)%mod;
}
int C(int n, int m){
    return f[n] * inv(f[m])%mod *inv(f[n-m])%mod;
}
void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << '\n';
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
    f[0] = 1;
    for(int i =1; i <N; i++)f[i] =  f[i-1] * i %mod;
    ans[0] = 0;
    for(int i = 1; i <= N; i ++){
        if(i%2 == 0){
            ans[i] = ans[i-1] ^ 1 ^ C(i, i/2);     
        }
        else ans[i] = ans[i-1] ^ 1;
    }
    while (t--)
    {
        solve();
    }
    return 0;
}
