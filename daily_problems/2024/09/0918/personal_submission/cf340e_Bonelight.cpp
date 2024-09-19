#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define pii pair<int, int>

void solve()
{
    int n; cin >> n;
    const int mo = 1e9 + 7;
    auto mypow = [&](int x, int y){
        int res = 1;
        while(y){
            if(y & 1) res = res * x % mo;
            y >>= 1;
            x = x * x % mo;
        }
        return res;
    };
    auto ni = [&](int x){
        return mypow(x, mo - 2);
    };

    vector<int> pre(n + 1, 1);
    for(int i = 1; i <= n; i ++){
        pre[i] = pre[i - 1] * i % mo;
    }
    auto C = [&](int x, int y){
        if(x > y) return 0ll;
        return pre[y] * ni(pre[x] * pre[y - x] % mo) % mo;
    };

    vector<int> a(n + 1), used(n + 1);
    int c = 0, s = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        if(a[i] == i) {cout << 0 << endl; return;}
        if(a[i] != -1) used[a[i]] = 1, c++;
    }
    for(int i = 1; i <= n; i ++) 
        s += (!used[i] && a[i] == -1);

    int ans = 0;
    for(int i = 0; i <= s; i ++){
        if(i & 1)  ans -= C(i, s) * pre[n - c - i] % mo;
        else ans += C(i, s) * pre[n - c - i] % mo;
        ans = (ans % mo + mo) % mo;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
    {
        solve();
    }
}
