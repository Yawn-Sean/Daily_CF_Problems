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
    int n, m;
    cin >> n >> m;
    vector<pii> a;
    for(int i=1; i<=n; i++) {
        int s, r;
        cin >> s >> r;
        a.push_back({s, r});
    }
    sort(a.begin(), a.end(), [&](pii x, pii y) {
        return x.second > y.second;
    });
    ll res = 0;
    vector<ll> sum(m+1), tot(m+1), f(n+1);
    for(auto &[s, r]: a) {
        sum[s] += r;
        tot[s] ++;
        if(sum[s] > 0) f[tot[s]] += sum[s];
        res = max(res, f[tot[s]]);
    }
    cout << res << endl;
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
