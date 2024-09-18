#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define pii pair<int, int>

void solve()
{
    int n,m; cin >> n >> m;
    
    int sign = 0;
    int zero = 0;
    unordered_map<int,int> mp;
    vector<int> a(n); for(int i = 0; i < n; i ++){
        cin >> a[i]; 
        if(a[i] == 0 && i + 1 != m){
            sign ++;
            a[i] = 2e18;
        } else if (i + 1 == m && a[i] != 0){
            a[i] = 0;
            sign ++;
            zero = 1;
        }
        mp[a[i]]++;
    }
    sort(begin(a),end(a));
    
    int cnt = 0;
    int ans = 1e18;
    for(int i = 0; i < n; i ++){
        if(i == 0 || (a[i] == a[i - 1] && a[i] != a[n - 1])) continue;
        cnt += max(a[i] - a[i - 1] - 1, 0ll);
        ans = min(ans, max(cnt - sign + zero, n - i - mp[a[i]] - sign + zero));
        ans = max(0ll, ans);    
    }    
    if(ans == 1e18) ans = 0;
    ans += sign;
    cout << ans << endl;
}  

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
