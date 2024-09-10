#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define pii pair<int, int>

void solve()
{
    int n,tot; cin >> n >> tot;
    int ans = 0;

    vector<int> a(n), val(n);
    for(int i = 0; i < n; i ++){
        cin >> a[i] >> val[i];
    }

    priority_queue<int> pq;
    vector<int> order(n);
    iota(begin(order),end(order),0);
    sort(begin(order),end(order), [&](int x, int y){
        return a[x] > a[y]; 
    });

    int tim = 0;
    for(auto i:order){
        pq.push(val[i]);
        tim += val[i];
        if(tim > tot){
            tim -= pq.top();
            pq.pop();
        }
        ans = max(ans, min((int)pq.size(),a[i]));
    }

    cout << ans << endl;
    cout << ans << endl;

    sort(begin(order),end(order), [&](int x, int y){
        return val[x] < val[y]; 
    });

    for(int i = 0, cur = 0; i < n; i ++){
        int o = order[i];
        if(a[o] >= ans && cur < ans){
            cur ++;
            cout << o + 1 << ' ';
        }
    }
    cout << endl;
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
