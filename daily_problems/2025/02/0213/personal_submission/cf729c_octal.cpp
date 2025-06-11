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
    int n, k, s, t;
    cin >> n >> k >> s >> t;
    vector<pii> cv(n+1);
    for(int i=1; i<=n; i++) {
        int c, v;
        cin >> c >> v;
        cv[i] = {c, v};
    }
    sort(cv.begin()+1, cv.end(), [&](pii x, pii y) {
        return x.second > y.second;
    });
    vector<int> g(k+1);
    for(int i=1; i<=k; i++)
        cin >> g[i];
    sort(g.begin()+1, g.end());
    vector<int> d;
    for(int i=1; i<=k; i++)
        d.push_back({g[i] - g[i-1]});
    d.push_back(s - g[k]);
    sort(d.begin(), d.end(), greater<int>());
    if(t < s) {
        cout << -1 << endl;
        return;
    }
    vector<int> minc(n+1);
    minc[1] = cv[1].first;
    for(int i=2; i<=n; i++)
        minc[i] = min(minc[i-1], cv[i].first);

    auto check = [&](int pos) {
        int v = cv[pos].second;
        if(d[0] > v) return false;
        ll tm = 0;
        for(int dx: d) {
            tm += 2*dx-min(dx, (v-dx));
        }
        return tm <= t;
    };
    int l = 1, r = n;
    while(l < r) {
        int mid = l+r+1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    if(!check(l)) cout << -1 << endl;
    else cout << minc[l] << endl;
}
