/*
    Bonelight * V *
    20241003: 放假的懒惰之日 
    No Coding, No Bug 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define INF (int)2e14
void solve()
{
    int n; cin >> n;
    vector<pii> a(n + 1);
    vector<int> idx(n + 1);
    iota(begin(idx),end(idx),0);
    for(int i = 1; i <= n; i ++){
        int x,y; cin >> x >> y;
        if(x > y) swap(x,y);  // 让 x <= y, 这样就不用关心谁躺着谁站着的问题了
        a[i] = {x,y};
    }
    
    sort(begin(idx) + 1, end(idx), [&](int idxX, int idxY){
        pii x = a[idxX], y = a[idxY];
        if(x.first != y.first) return x.first < y.first;
        return x.second > y.second;
    });

    vector<int> ans(n + 1, -1);
    int cur = -1;
    int w = INF;
    for(int i = 1; i <= n; i ++){
        int o = idx[i];
        if(a[o].second <= w){
            cur = o;
            w = a[o].second;
        } else {
            ans[o] = cur;
        }
    }

    for(int i = 1; i <= n; i ++) cout << ans[i] << ' ';
    cout << endl;
}  

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1; cin >> T;
    while(T --){
        solve();
    }
}
