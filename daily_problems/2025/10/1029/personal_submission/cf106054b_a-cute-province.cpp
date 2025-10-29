#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 998244353;
const int N = 3e5 + 10;
int qpow(int a,int b){
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
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> b(n), l(n+1), c(n+1);
    for(int i = 1; i <= n-k+1; i ++)cin >> b[i];
    for(int i = 1; i <= n-k; i ++)l[i] =  b[i+1] - b[i];
    for(int i = 1; i <= k; i ++)c[i] = l[i];
    for(int i = 1+k; i <= n-k; i ++){
        l[i] += l[i-k];
        int j = (i-1)%k+1;
        c[j] = min(c[j], l[i]);
    }
    int sum = 0;
    for(int i =1 ; i <= k ; i ++)sum += max(0ll, -c[i]);
    if(sum > b[1]){
        cout << 0 << '\n';
        return;
    }
    else{
        sum = b[1] - sum;
        int up = 1, down = 1;
        for(int i = sum+1; i <= sum+k-1; i ++)up *= i, up%=mod;
        for(int i = 1; i < k; i ++)down *= i, down %= mod;
        cout << up * inv(down)%mod << '\n';
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
