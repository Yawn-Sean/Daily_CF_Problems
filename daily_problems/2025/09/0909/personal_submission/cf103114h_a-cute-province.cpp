#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e5+10; 
const int mod = 1e9 + 7;
int f[N];
int qpow(int a, int b){
    int res = 1;
    while(b){
        if(b&1)res = res * a %mod;
        b >>= 1;
        a = a * a %mod;
    }
    return res;
}
int inv(int x){return qpow(x, mod-2);};
int C(int n, int m){
    return f[n] * inv(f[m])%mod * inv(f[n-m])%mod;
}
void solve()
{
    int n, m;
    cin >> n >> m;
   if(n == 1 && m == 1){
        cout << 1 << '\n';
    }
    else if(n > m/2){
        cout << 0 << '\n';
    }
    else{
        cout << C(m-n-1, n-1) *m%mod * f[n-1] %mod<< '\n';
    }
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t;
     cin >> t;
     f[0] = 1;
     for(int i = 1; i < N; i ++)f[i] = f[i-1] * i %mod;
     //t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
