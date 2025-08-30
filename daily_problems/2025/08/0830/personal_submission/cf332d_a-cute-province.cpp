#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e3+10; 
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
    if(m > n)return 0ll;
    return f[n] * inv(f[m])%mod * inv(f[n-m])%mod;
}
void solve()
{
   int n, k;
   cin >> n >> k;
   vector<vector<int>> g(n+1, vector<int> (n+1));
   for(int i = 1; i <=n; i ++){
        for(int j = i +1; j <= n; j ++){
            cin>> g[i][j];
            g[j][i] = g[i][j];
        }
   }
   int sum1 = 0, sum2 = 0;
   for(int i  =1;  i<=n; i ++){
    int m = 0, sum = 0;
    for(int j = 1; j <= n; j++){
        if(g[i][j] == -1 || i == j)continue;
       m ++;
       sum += g[i][j];
    }
    sum1 += sum * C(m-1, k-1);
    sum2 += C(m, k);
   }  
   cout << sum1/ sum2 << '\n';
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t;
    //cin >> t;
    f[0] = 1;
    for(int i=  1; i < N; i ++)f[i] = f[i-1] * i%mod;
     t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
