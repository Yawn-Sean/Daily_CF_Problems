#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e5 + 10, mod = 1e9 + 7;
int n, m, k;

long double angles[N];
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        angles[i] = atan2l(y, x);
    }

    sort(angles, angles + n);

    long double ans = 0, pi = atan2l(0, -1);
    for (int i = 1; i < n; i++)
        ans = max(ans, angles[i] - angles[i - 1]);
    ans = max(ans, 2 * pi - angles[n - 1] + angles[0]);

    cout << fixed << setprecision(10) << (2 * pi - ans) / pi * 180 << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }

    return 0;
}
