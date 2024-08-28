#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>

void solve()
{
    int n; cin >> n; 
    int diff = 0;
    vector<int> a(n + 1); for(int i = n; i >= 1; i --) cin >> a[i], diff += a[i] == 1? 1:-1;
    vector<int> b(n + 1); for(int i = 1; i <= n; i ++) cin >> b[i], diff += b[i] == 1? 1:-1;

    unordered_map<int,int> mp; mp[0] = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i ++){   // 计算贡献
        if(a[i] == 1) cnt ++;
        else cnt --;
        if( !mp.count(cnt)) mp[cnt] = i;
    }

    int ans = 2 * n;
    if(mp.count(diff)) ans = mp[diff];
    
    for(int i = 1; i <= n; i ++){  // 匹配贡献
        if(b[i] == 1) diff --;
        else diff ++;
        if(mp.count(diff)){
            ans = min(ans, mp[diff] + i);
        }
    }
    cout << ans << endl;
} 
 
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1; cin >> T;
    while (T--)
        solve();
}
