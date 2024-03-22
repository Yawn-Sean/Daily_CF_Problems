#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
inline void solve()
{
    int n, l;
    cin >> n >> l;
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=2; i<=n; i++)
        a[i] = min(a[i], a[i-1]*2);
    for(int i=n-1; i>=1; i--)
        a[i] = min(a[i], a[i+1]);
    vector<int> r;
    while(l) {
        r.push_back(l % 2);
        l /= 2;
    }
    int sz = r.size();
    while(a.size() <= sz+1) {
        a.push_back(a.back()*2);
    }
    ll res = 0;
    for(int i=0; i<sz; i++) {
        res = min(res, a[i+1]);
        res += a[i+1] * r[i];
    }
    cout << min(res, a[sz+1]) << endl;
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
