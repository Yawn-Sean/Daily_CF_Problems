#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    int n;
    cin>>n;

    unordered_map<ll, ll> sumx, sumy;
    unordered_map<ll, vector<pair<ll,int>>> byx, byy;
    byx.reserve(n*2);
    byy.reserve(n*2);

    for (int i = 0; i < n; ++i) {
        ll x, y; int v;
        cin >> x >> y >> v;
        sumx[x] += v;
        sumy[y] += v;
        byx[x].push_back({y, v});
        byy[y].push_back({x, v});
    }

    ll ans = 0;
    //同类型三条的情况
    vector<ll> sx, sy;
    sx.reserve(sumx.size()); sy.reserve(sumy.size());
    for (auto &p: sumx) sx.push_back(p.second);
    for (auto &p: sumy) sy.push_back(p.second);
    sort(sx.rbegin(), sx.rend());
    sort(sy.rbegin(), sy.rend());
    if (!sx.empty()) ans = max(ans, sx[0]);
    if (!sy.empty()) ans = max(ans, sy[0]);
    ll tmp = 0;
    for (int i = 0; i < (int)sx.size() && i < 3; ++i) tmp += sx[i];
    ans = max(ans, tmp);
    tmp = 0;
    for (int i = 0; i < (int)sy.size() && i < 3; ++i) tmp += sy[i];
    ans = max(ans, tmp);

    {
        multiset<ll> ms;
        for (auto &p: sumy) ms.insert(p.second);
        for (auto &px: byx) {
            ll x = px.first;
            vector<pair<ll,int>> &pts = px.second;
            for (auto &pr: pts) {
                ll y = pr.first; int v = pr.second;
                auto it = ms.find(sumy[y]);
                ms.erase(it);
                ms.insert(sumy[y] - v);
            }
            ll t1 = 0, t2 = 0;
            if (!ms.empty()) {
                auto it1 = prev(ms.end());
                t1 = *it1;
                ms.erase(it1);
                if (!ms.empty()) t2 = *prev(ms.end());
                ms.insert(t1);
            }
            ans = max(ans, sumx[x] + t1 + t2);
            for (auto &pr: pts) {
                ll y = pr.first; int v = pr.second;
                auto it = ms.find(sumy[y] - v);
                ms.erase(it);
                ms.insert(sumy[y]);
            }
        }
    }

    {
        multiset<ll> ms;
        for (auto &p: sumx) ms.insert(p.second);
        for (auto &py: byy) {
            ll y = py.first;
            vector<pair<ll,int>> &pts = py.second;
            for (auto &pr: pts) {
                ll x = pr.first; int v = pr.second;
                auto it = ms.find(sumx[x]);
                ms.erase(it);
                ms.insert(sumx[x] - v);
            }
            ll t1 = 0, t2 = 0;
            if (!ms.empty()) {
                auto it1 = prev(ms.end());
                t1 = *it1;
                ms.erase(it1);
                if (!ms.empty()) t2 = *prev(ms.end());
                ms.insert(t1);
            }
            ans = max(ans, sumy[y] + t1 + t2);
            for (auto &pr: pts) {
                ll x = pr.first; int v = pr.second;
                auto it = ms.find(sumx[x] - v);
                ms.erase(it);
                ms.insert(sumx[x]);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    //cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
