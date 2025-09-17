#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 1e9 + 7;
int qpow(int a,int b){
    int res =1 ;
    while(b){
        if(b & 1)res = res * a%mod;
        b >>= 1;
        a = a * a%mod;
    }
    return res;
}
int inv(int x){
    return qpow(x, mod - 2)%mod;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        sum %= mod;
    }
    int ans = 1;
    for(int x = 1; x < n; x ++){
        ans += n/std::gcd(x, n);
        ans %=mod;
    }
    cout << ans * sum%mod *inv(n * n%mod)%mod << '\n';
}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    //t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
