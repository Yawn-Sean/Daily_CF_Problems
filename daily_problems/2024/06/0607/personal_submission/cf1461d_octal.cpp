#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
inline void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1), pre(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    sort(a.begin()+1, a.end());
    for(int i=1; i<=n; i++)
        pre[i] = pre[i-1] + a[i];
    queue<pii> Q;
    Q.push({1, n});
    set<ll> st;
    set<pii> vis;
    vis.insert({1, n});
    st.insert(pre[n]);
    while(!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();
        ll m = (a[x]+a[y]) / 2;
        int l=x, r=y;
        while(l < r) {
            int mid = l+r+1 >> 1;
            if(a[mid] <= m) l = mid;
            else r = mid - 1;
        }
        st.insert(pre[l] - pre[x-1]);
        st.insert(pre[y] - pre[l]);
        if(l - x > 0 && !vis.count({x, l}))
            Q.push({x, l}), vis.insert({x, l});
        if(y - l - 1 > 0 && !vis.count({l+1, y}))
            Q.push({l+1, y}), vis.insert({l+1, y});
    }
    for(int i=1; i<=q; i++) {
        ll s;
        cin >> s;
        if(st.count(s)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
