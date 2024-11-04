#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>

void solve()
{
    int x1,y1,t1; cin >> x1 >> y1 >> t1;
    int x2,y2,t2; cin >> x2 >> y2 >> t2;

    int a = y1 - x1 + 1;
    int b = y2 - x2 + 1;
    int d = gcd(t1,t2), gap = x1 - x2;
    gap = (gap % d + d) % d;

    cout << max({0ll, min(a,b - gap), min(a-(d - gap), b)}) << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
        solve();
}
