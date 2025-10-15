#include <bits/stdc++.h>
#define x first
#define y second
#define int  long long
#define cute_prov0nce main
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6 + 10; 
const int MAX = 9e18;
const int mod = 1e9 + 7;
void solve()
{
    int q;
    cin >> q;
    while(q--){
        int l, r, ans = 0;
        cin >> l>> r;
        int fl, fr, gl, gr, L, R;
        for(int y = 2; ; y ++){
            fl = max(l, 1ll << y), fr = min(r, (1ll << (y+1))-1);
            if(fr < l)continue;
            if(fl > r)break;
            gl = y ;
            
            for(int z = 1; ; z ++){
                if(gl > MAX/y)gr = r;
                else gr = gl * y -1;
                L = max(fl, gl);
                R = min(fr, gr);
                if(L <= R){
                   
                    ans += (R-L+1)%mod * z%mod;
                    //cout << ans << '\n';
                    ans %= mod;
                }
                if(gl > fr / y)break;
                gl *= y;
            }
            
        }
        cout << ans << '\n';
    }

}
signed cute_prov0nce()
{
     //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
