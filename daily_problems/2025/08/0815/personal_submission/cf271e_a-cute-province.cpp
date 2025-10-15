#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e5+10    ; 
const int mod = 1e9 + 7;
/*
    d = y -x;
    操作1和3可以合成任意k*d差值的牌, 1和2又可以将差值中2因数去除,所以也就相当于可以合成任意k*q(去除了d的2的因数)差值的牌
*/
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), v;
    int q = 0;
    for(int i =1; i <= n; i++)cin >> a[i], q =std::gcd(q, a[i]-1);
    
    for(int i = 1; i <= sqrt(q); i ++){
        if(q%i != 0)continue;
        int x1 = i, x2 = q/i;
        if(x1&1)v.emplace_back(x1);
        if(x2&1 && x1 != x2)v.emplace_back(x2);
    }
    int ans = 0;
    for(auto u : v){
        int d = u;
        
        while(d  <= m){
            ans += m - d;
            d *= 2;
        }
    }   
    cout << ans << '\n';
    
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);      
     // 取消同步流
     int t;
     //cin >> t;
     t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
