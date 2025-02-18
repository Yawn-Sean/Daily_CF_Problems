#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>
 
void solve()
{
    int n,l,r; cin >> n >> l >> r;
    l --, r --;
    function<int(int,int,int)> dfs = [&](int x,int l,int r){
        if(x == 0 || x == 1) {
            return x;
        }
  
        int bi = ( 1ll << (63 - __builtin_clzll(x)) )- 1;
        int ans = 0;
        if(bi > l) ans += dfs(x / 2, l, min(r, bi - 1));
        if(bi >= l && bi <= r) ans += x & 1;
        if(bi < r) ans += dfs(x / 2,max(0ll, l - bi - 1), r - bi - 1);
        return ans;
    };
    int ans = dfs(n,l,r);
    cout << ans << endl;
}
 
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
        solve();
}
