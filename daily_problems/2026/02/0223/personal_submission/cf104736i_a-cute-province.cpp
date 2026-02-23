#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9 + 7;
const int N = 2e5 + 10;
void solve()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> s_all(26), s_now(26);
    for(auto &c : s)s_all[c-'a'] ++;
    int ans = 0;
    for(auto &c : s){
        int p = c - 'a';
        for(int i = p + 1; i <= 25; i ++){
            ans += (__int128_t)(n-1)*n/2%mod * s_all[i]%mod, ans %= mod;
            ans += n%mod * s_now[i]%mod, ans %= mod;
        }
        //cout << ans << '\n';
        s_now[p] ++;
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
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
