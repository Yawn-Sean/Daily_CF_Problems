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
    double res = 1e9;
    vector<pdd> p(n+1);
    for(int i=1; i<=n; i++)
        cin >> p[i].first >> p[i].second;
    for(int i=1; i<=n; i++) {
        int a = i-1;
        int b = i+1;
        if(a == 0) a = n;
        if(b == n+1) b = 1;
        pdd ia = {p[a].first-p[i].first, p[a].second-p[i].second};
        pdd ib = {p[b].first-p[i].first, p[b].second-p[i].second};
        pdd ab = {p[a].first-p[b].first, p[a].second-p[b].second};
        double S = abs(ia.first*ib.second - ia.second*ib.first) * 0.5;
        double d = sqrt(ab.first*ab.first + ab.second*ab.second);
        res = min(res, S/d);
    }
    cout << res << endl;
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
