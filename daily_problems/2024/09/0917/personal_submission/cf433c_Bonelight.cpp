#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define pii pair<int, int>

void solve()
{
    int n,m; cin >> n >> m;
    vector<int> a(m + 1);
    for(int i = 1;  i <= m; i ++){
        cin >> a[i];    
    }

    vector<int> page(n + 1);
    vector<vector<int>> nei(n + 1,vector<int>());
    
    int sum = 0;
    for(int i = 2; i <= m; i ++){
        int d = abs(a[i] - a[i - 1]);
        sum += d;

        if(a[i] != a[i - 1]){
            page[a[i]] += d;
            page[a[i - 1]] += d;
            nei[a[i]].push_back(a[i - 1]);
            nei[a[i - 1]].push_back(a[i]);
        }
    }
    // cout << sum << endl;
    int ans = 2e18;
    for(int i = 1; i <= n; i ++){
        if(nei[i].size()){
            sort(begin(nei[i]), end(nei[i]));
            int x = nei[i][nei[i].size() / 2];

            int tmp = 0;
            for(auto o:nei[i]) tmp += abs(o - x);
            ans = min(ans,sum - (page[i] - tmp));
        }
    }
    if(ans == 2e18) ans = 0;
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
