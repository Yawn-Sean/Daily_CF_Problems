#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define pii pair<int, int>

void solve()
{
    const int mo = 1e9 + 7;
    int n,c1,c2; cin >> n >> c1 >> c2;
    vector<pii> a(n);
    for(auto &[x,y]:a) cin >> x >> y;
    sort(begin(a),end(a));

    priority_queue<int,vector<int>,greater<int>> pq_using;
    priority_queue<int> pq_used;
    
    int ans = 0;
    for(auto [x,y]:a){
        ans = (ans + c2 * (y - x + 1)) % mo;
    }
    // cout << ans << endl;
    for(auto [x,y]:a){
        while(pq_using.size() && pq_using.top() <= x){
            int v = pq_using.top();
            pq_used.push(v);
            pq_using.pop();
        }

        if(pq_used.size() && (x - pq_used.top()) * c2 < (c1 - c2)){
            ans += (x - pq_used.top()) * c2 ;
            pq_used.pop();
        }else{
            ans += c1 - c2;
        }
        if(ans >= mo) ans %= mo;
        pq_using.push(y + 1);
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
