#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;
int n, m, k;

void solve()
{
    int h1, a1, d1;
    int h2, a2, d2;
    cin >> h1 >> a1 >> d1;
    cin >> h2 >> a2 >> d2;
    int costh, costa, costd;
    cin >> costh >> costa >> costd;

    int total = max(0, d2 - a1 + 1) * costa;
    a1 = max(a1, d2 + 1);
    int ans = max(0, a2 - d1) * costd + total;

    for (int i = 0; i <= 100; i++)
        for (int j = 0; j + d1 < a2; j++)
        {
            int cost = i * costa + j * costd;
            a1 += i, d1 += j;
            int blood2 = a1 - d2;
            int t2 = (h2 + blood2 - 1) / blood2;
            int blood1 = a2 - d1;
            int need_blood = t2 * blood1 + 1;
            cost += max(0, need_blood - h1) * costh;
            a1 -= i, d1 -= j;
            ans = min(ans, cost + total);
        }
    cout << ans << '\n';
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
