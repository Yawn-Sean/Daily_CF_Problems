#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define pii pair<int, int>

void solve()
{
    int mo = 998244353;
    int n,m,k; cin >> n >> m >> k;
    auto M = [&](int x){
        return (x % mo + mo) % mo;
    };
    auto mypow = [&](int x, int y){
        int res = 1;
        while(y){
            if(y & 1) res = res * x % mo;
            x = x * x % mo;
            y >>= 1;
        }
        return res;
    };
    vector<int> a(m); for(auto &i:a) cin >> i;
    int ans = 1, lt = 0;
    for(auto i:a){
        int v = mypow(k, i - lt);
        ans = M(ans * M(v * (v + 1) / 2));
        lt = i;
    }
    cout << M(mypow(k, n - lt * 2) * ans) << endl;
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
