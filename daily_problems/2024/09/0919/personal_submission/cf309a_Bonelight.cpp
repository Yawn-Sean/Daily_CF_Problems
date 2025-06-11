#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define pii pair<int, int>

void solve()
{
    int n,l,t; cin >> n >> l >> t;
    vector<int> a(n*2);
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        a[i + n] = a[i] + l;
    }
    sort(begin(a),begin(a));
    int d = t * 2 % l;
    double ans = n * (n - 1) * (t * 2 / l);
    for(int i = 0; i < n; i ++){
        ans += upper_bound(begin(a),end(a),a[i] + d) - 1 - a.begin() - i;
    }
    cout << fixed << setprecision(20) << ans / 4 << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
    {
        solve();
    }
}
