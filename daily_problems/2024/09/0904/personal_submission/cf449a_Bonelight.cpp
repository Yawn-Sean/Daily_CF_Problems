#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>

void solve()
{
    int n,m,k; cin >> n >> m >> k;
    if(n + m - 2 < k){
        cout << -1 << endl;
        return;
    } 

    auto f = [&](int x){
        return x * ( m / max(1ll, k - (n / x - 1) + 1) );
    };

    int ans = -2e18;
    for(int i = sqrt(n) + 1; i >= 1; i --){
        ans = max({ans, f(i), f(n / i)});
    }
    cout << ans << endl << endl;
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
