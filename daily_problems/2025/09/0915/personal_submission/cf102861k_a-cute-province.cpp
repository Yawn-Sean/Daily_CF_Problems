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
void solve()
{
    int p, f;
    cin >> p >> f;
    vector<__int128_t> ve(p);
    vector<int> cnt(p);
    __int128_t one = 1;
    for(int i = 1; i <= f; i ++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        cnt[u] ^= 1;
        cnt[v] ^= 1;
        ve[u] |= one << v + 1;
        ve[v] |= one << u + 1;
    }
    for(int i = 0 ;i < p; i ++){
        if(cnt[i])ve[i] |= one << i +1;
        else ve[i] |= 1;
    }
    vector<__int128_t> base(p+1);
    for(auto &x : ve){
        for(int i = p ;i >= 0; i --){
            if(x >> i & 1){
                if(base[i]){
                    x ^= base[i];
                }
                else{
                    base[i] = x;
                    break;
                }
            }
            
        }
    }
    cout << (base[0]? "N" : "Y") << '\n';
    

}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
