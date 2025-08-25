#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 3e5+10; 
const int mod = 1e9 + 7;
/*
    考虑对角线上点的个数对应的情况, 选i个点就是有i/2组,计数
*/
int f[N], g[N];
int qpow(int a, int b){
    int res =1;
    while(b){
        if(b&1)res = res * a%mod;
        b >>= 1;
        a = a * a %mod;
    }
    return res;
}
int inv(int x){
    return qpow(x, mod -2);
}
int C(int n, int m){
    return f[n]*inv(f[m])%mod*inv(f[n-m])%mod;
}
void solve()
{
   int n, k;
   cin >> n >> k;
   int cnt = 0;
   for(int i = 1; i <= k; i++){
    int r,c;
    cin >> r>> c;
    if(r == c)cnt++;
   }
   k=k*2-cnt;
   int ans = 0, last = n-k;
   for(int i = 0; i <= (n-k); i +=2){
        ans += C(n-k, i) * g[i]%mod * qpow(2, i/2)%mod;
        ans %= mod;
   }
   cout << ans << '\n';
   
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     // 取消同步流
     f[0] =1;
     g[0] = 1;
     for(int i =  1; i < N; i ++)f[i] = f[i-1]*i%mod;
     for(int i =  2; i < N; i +=2)g[i] = g[i-2]*(i-1)%mod;
     int t;
     cin >> t;
     //t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
