#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
inline void solve()
{
    int n;
    cin >> n;
    vector<int> f(n+5);
    for(int i=1; i<=n; i++)
        cin >> f[i];
    for(int i=1; i<=n; i++)
    if(f[f[i]] != f[i]) {
        cout << -1 << endl;
        return;
    }
    vector<int> g, h;
    g.push_back(0);
    h.push_back(0);
    map<int, int> mp;
    int tot = 1;
    for(int i=1; i<=n; i++) {
        if(mp.count(f[i])) g.push_back(mp[f[i]]);
        else {
            mp[f[i]] = tot;
            g.push_back(tot);
            h.push_back(f[i]);
            tot ++;
        }
    }
    int m = h.size()-1;
    cout << m << endl;
    for(int i=1; i<=n; i++)
        cout << g[i] << " ";
    cout << endl;
    for(int i=1; i<=m; i++)
        cout << h[i] << " ";
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
