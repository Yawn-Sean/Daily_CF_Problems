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
const int N = 5000 + 10;
int qpow(int a, int b){
    int res =1;
    while(b){
        if(b & 1)res = res * a %mod;
        b >>= 1;
        a = a * a %mod;
    }
    return res;
}
void solve()
{   
    int k, x;
    cin >> k >> x;
    cout << x * qpow(k+1, __builtin_popcount(x) - 1)%mod << '\n';
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
    while (t--)
    {
        solve();
    }
    return 0;
}
