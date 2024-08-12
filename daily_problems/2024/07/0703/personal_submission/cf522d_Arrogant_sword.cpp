// LUOGU_RID: 149717251

#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int inf = 1e12;


void solve() 
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), b(n);
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        b[i-1] = a[i];
        
    }
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    int nn = b.size();
    map<int,int> mp;
    for (int i = 0; i < nn; i ++ ) {
        mp[b[i]] = i + 1;
    }
    vector<int> pre(n+1), pos(n+1);
    for (int i = 1; i <= n; i ++ ) {
        int idx = mp[a[i]];
        pre[i] = pos[idx];
        pos[idx] = i;
    }

    SegmentTree tr;
    tr.init(n, a);
    
    vector<pair<int,int>> q[n+1];
    for (int i = 0; i < m; i ++ ) {
        int l, r;
        cin >> l >> r;
        q[r].push_back({l, i});
    }

    vector<int> ans(m);
    for (int i = 1; i <= n; i ++ ) {
        if (pre[i]) tr.update(1, pre[i], i - pre[i]);
        for (auto [l, id]: q[i]) {
            
            ans[id] = tr.query(1, l, i);
        }
    }
    
    for (int i = 0; i < m; i ++ ) {
        if (ans[i] == inf) cout << -1 << endl;
        else cout << ans[i] << endl;
    }

    cout << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
    
}