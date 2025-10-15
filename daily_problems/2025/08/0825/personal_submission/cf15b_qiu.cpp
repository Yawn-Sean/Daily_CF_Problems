#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005, mod = 998244353;

void solve()
{
    int n, m, x1, x2, y1, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2)
        swap(x1, x2);
    if (y1 > y2)
        swap(y1, y2);
    int a = x1 + n - x2;
    int b = y1 + m - y2;
    cout << n * m - 2 * a * b + max(0ll, 2 * a - n) * max(0ll, 2 * b - m) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;

    cin >> T;
    while (T--)
        solve();
    return 0;
}
