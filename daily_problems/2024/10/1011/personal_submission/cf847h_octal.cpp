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
    int n;
    cin >> n;
    vector<ll> a(n+1), b(n+1), c(n+1);
    ll sum = 0;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    b[1] = a[1];
    for(int i=2; i<=n; i++)
        b[i] = max(b[i-1]+1, a[i]);
    c[n] = a[n];
    for(int i=n-1; i>=1; i--)
        c[i] = max(c[i+1]+1, a[i]);
    vector<ll> preb(n+5), prec(n+5);
    for(int i=1; i<=n; i++)
        preb[i] = preb[i-1] + b[i];
    for(int i=n; i>1; i--)
        prec[i] = prec[i+1] + c[i];
    ll res = 2e18;
    
    for(int i=1; i<=n; i++)
        res = min(res, preb[i-1]+prec[i+1]+max(b[i], c[i]));

    cout << res-sum << endl;
    
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
