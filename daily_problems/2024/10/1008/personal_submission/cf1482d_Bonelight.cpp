/*
    Bonelight * V *
    20241008: %%%
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
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];

    vector<int> pre(n), sub(n);
    iota(begin(pre), end(pre), -1); pre[0] = n - 1;
    iota(begin(sub), end(sub), 1); sub[n - 1] = 0;
    queue<int> q; for(int i = 0; i < n; i ++) q.push(i);
    
    vector<int> ans;
    vector<int> del(n);
    while(q.size()){
        int x = q.front(); q.pop();
        int y = sub[x];
        if(del[x]) continue;

        if(__gcd(a[x],a[y]) == 1){
            del[y] = 1;
            ans.push_back(y + 1);
            pre[sub[y]] = pre[y];
            sub[pre[y]] = sub[y];
            q.push(x);
        }
    }
    cout << ans.size() << ' ';
    for(auto i:ans) cout << i << ' ';
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
