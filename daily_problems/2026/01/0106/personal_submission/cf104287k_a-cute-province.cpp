#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9+7;
const int N = 1e6 + 10;
int f[N], g[N];
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
    return qpow(x, mod-2);
}
void solve()
{
    string s;
    cin >> s;
    vector<int> a(26);
    int cnt = 0;
    for(auto &c : s){
        if(c != '?')a[c-'a']++;
        else cnt ++;
    }
    vector<int> dp(cnt+1);
    dp[0] = 1;
    for(int k = 0; k < 26; k ++){
        vector<int> ndp(cnt+1);
        for(int i = 0; i <= cnt; i ++){
            for(int j = 0; j + i <= cnt; j ++){
                ndp[j+i] += dp[i] * g[j]%mod * g[a[k]+j]%mod;
                ndp[j+i] %= mod;
            }
        }
        dp = ndp;
    }
    cout << f[s.size()] * f[cnt]%mod * inv(qpow(26, cnt))%mod * dp[cnt]%mod << '\n';
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
    for(int i =1 ; i< N; i ++)f[i] = f[i-1] * i %mod;
    g[N-1] = inv(f[N-1]); 
    for(int i = N-1 ; i >= 1; i --)g[i-1] = g[i] * i %mod;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
