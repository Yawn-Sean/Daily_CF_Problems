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
const int N = 2e5 + 10, mod = 1e9 + 7;
int n, m, k;

void solve()
{
    cin >> n >> m;
    LL total = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, d;
        cin >> x >> d;
        total += x * n;
        if (d >= 0)
        {
            total += 1ll * d * n * (n - 1) / 2;
        }
        else
        {
            int pos = n / 2;
            total += 1ll * d * pos * (pos + 1);
            if (n % 2 == 0)
                total -= d * pos;
        }
    }
    cout << fixed << setprecision(15) << (1.0 * total / n) << '\n';
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
