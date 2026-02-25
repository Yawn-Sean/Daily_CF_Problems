#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e4 + 10;
int qpow(int a, int b, int mod){
    int res =1;
    while(b){
        if(b&1)res = res * a %mod;	
        b >>= 1;
        a = a * a %mod;
    }
    return res;
}
int inv(int x, int mod){
    return qpow(x, mod-2, mod);
}
int fact[N], inv_fact[N];
void init_fact(int mod){
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    inv_fact[N-1] = qpow(fact[N-1], mod-2, mod);
    for (int i = N-2; i >= 0; i--) {
        inv_fact[i] = inv_fact[i+1] * (i+1) % mod;
    }
}
void solve()
{
    int n, mod;
    cin >> n >> mod;
    vector<int> e(n+1);
    init_fact(mod);
    e[1] = 0;
    cout << 0 << ' ';
    for(int i = 2; i <= n;i  ++){
        int p = (qpow(2, i, mod) - 2 + mod) % mod;
        int sum = 0;
        for(int j = 1; j < i; j ++){
            sum += fact[i] * inv_fact[i-j]%mod * inv_fact[j] %mod * (e[j] + 1) %mod;
            sum %= mod;
        }
        int b = qpow(3, i-1, mod);
        sum += (b -  p + mod) %mod;
        sum %= mod;
        e[i] = sum * inv(p, mod) %mod;
        cout << e[i] <<' ';
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
