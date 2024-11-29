#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using PII = pair<int,int>;
#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define lowbit(x) (x) & (-x)
#define endl "\n" 
#define pb push_back
#define point(x) setiosflags(ios::fixed)<<setprecision(x)
#define debug(x) cerr << #x << " = " << x << endl
const int N=1e5+10;
const int INF=0x3f3f3f3f;
const int mod=998244353;

void solve()
{
    int n, m, k, q; cin >> n >> m >> k >> q;
    vector<array<int, 3>> p(q);
    int mx = -1;
    for(auto &[x, y, t] : p) {
        cin >> x >> y >> t;
        mx = max(mx, t);
    }
    int l = 0, r = mx + 10;
    auto check = [&](int mid) {
        vector g(n + 1, vector<int> (m + 1));
        for(auto &[x, y, t] : p) {
            if(t <= mid)
                g[x][y] = 1;
        }
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
            }
        }
        // for(int i = 1; i <= n; i ++) {
        //     for(int j = 1; j <= m; j ++) {
        //         cout << i << ' ' << j << ' ' << g[i][j] << endl;
        //     }
        // }
        //assert(0);
        for(int i = k; i <= n; i ++) {
            for(int j = k; j <= m; j ++) {
                int d = i - k + 1, l = j - k + 1;
                int num = g[i][j] - g[i][l - 1] - g[d - 1][j] + g[d - 1][l - 1];
                //cout << i << ' ' << j << ' ' << d << ' ' << l << ' ' << num << endl;
                if(num == k * k) {
                    
                    return 1;
                }
            }
        }        
        return 0;
    };
   // cout << check(8) << endl;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(!check(l)) cout << -1 << endl;
    else cout << l << endl;

}
int main()
{
    IOS;
    int T = 1;
    //cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
