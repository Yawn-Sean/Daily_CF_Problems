#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>
 


void solve()
{
    int n; cin >> n;
    vector<int> a(n); for(auto &i:a) cin >> i, i = -i;
    vector<int> li;
    vector<vector<int>> ans;
    for(auto i:a){
        int idx = lower_bound(begin(li),end(li),i) - begin(li);
        if(idx == li.size()){
            li.push_back(i);
            ans.push_back({i});
        } else {
            li[idx] = i;
            ans[idx].push_back(i);
        }
    }
    for(auto i:ans){
        for(auto j:i){
            cout << -j << ' ';
        }
        cout << endl;
    }
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
