/*
    Bonelight * V *
    20241005: 放假的懒惰之日 
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
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];

    vector<int> X(n + 1);
    iota(begin(X),end(X),0);
    function<int(int)> find = [&](int x) {return X[x] = X[x] == x? x:find(X[x]);};
    auto merge = [&](int xx, int yy){
        int x = find(xx), y = find(yy);
        if(x == y) return;
        X[y] = x;
    };

    while(m --){
        int x,y; cin >> x >> y;
        merge(x,y);
    }
    
    vector<vector<int>> g(n + 1, vector<int>());
    for(int i = 1; i <= n; i ++){
        g[find(i)].push_back(a[i]);
    }

    int ans = 0;
    for(auto uni:g){
        map<int,int> cnt;
        int mx = 0;
        for(auto c:uni){
            cnt[c] ++;
            mx = max(mx, cnt[c]);
        }
        ans += uni.size() - mx;
    }
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
