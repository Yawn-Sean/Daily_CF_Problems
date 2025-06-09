#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
inline void solve()
{
    int n;
    cin >> n;
    vector<int> fa(n+1), lc(n+1), rc(n+1), a(n+1);
    multiset<pii> st;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        auto p = st.upper_bound({a[i], n});
        auto [val, idx] = *p;
        if(lc[idx] == 0) {
            lc[idx] = i;
            fa[i] = idx;
        } else {
            auto t = *(prev(p));
            idx = t.second;
            rc[idx] = i;
            fa[i] = idx;
        }
        st.insert({a[i], i});
    }
    for(int i=2; i<=n; i++)
        cout << a[fa[i]] << " ";
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}
