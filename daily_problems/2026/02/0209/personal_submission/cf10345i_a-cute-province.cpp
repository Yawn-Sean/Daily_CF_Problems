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
const int N = 1e6 + 10;
int f[N];
int qpow(int a, int b){
    int res = 1;
    while(b){
        if(b & 1)res = res * a %mod;
        b >>= 1;
        a = a * a %mod;
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    string  sa, sb, sc;
    cin >> sa >> sb >> sc;
    int m = sa.size();
    int ans = 1;
    int o = qpow(2, n-1);
    int odd, even;
    if(n & 1)odd = even = o-1;
    else odd = o, even = o - 2;
    for(int i = 0; i < m; i ++){
        if(sa[i] == '1'){
            if(sb[i] == '0'){
                ans = 0;
            }
            else{
                if(sc[i]-'0' != (n&1))ans = 0;
            }
        }
        else{
            if(sb[i] == '0'){
                if(sc[i]-'0' != 0)ans = 0;
            }
            else{
                if(sc[i]-'0')ans *= odd;
                else ans *= even;
            }
        }
        ans %= mod;
    }
    cout << ans << '\n';

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
    f[0] = 1;
    for(int i = 1; i < N; i ++)f[i] = f[i-1] * i %mod;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
