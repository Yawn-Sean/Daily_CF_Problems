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
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    ll sum = 0, maxv = 0;
    for(int i=1; i<=n; i++)
        sum += a[i], maxv = max(maxv, a[i]);
    cout << min(sum - maxv, sum / 3) << endl;
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
