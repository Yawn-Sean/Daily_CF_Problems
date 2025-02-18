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
    cin >> n >> k;
    LL total = 1ll * k * (k - 1);
    if (total < n)
    {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';

    for (int i = 2; i <= k; i++)
    {
        int x = i, y = 1;
        bool ok = false;
        while (x >= 1 && y <= k)
        {
            if (n == 0)
            {
                ok = true;
                break;
            }
            if (x == y)
                x--, y++;
            cout << x << ' ' << y << '\n';
            n--;
            x--, y++;
        }
        if (ok)
            break;
    }

    for (int j = 2; j < k; j++)
    {
        int x = k, y = j;
        bool ok = false;
        while (x >= 1 && y <= k)
        {
            if (n == 0)
            {
                ok = true;
                break;
            }
            if (x == y)
                x--, y++;
            cout << x << ' ' << y << '\n';
            n--;
            x--, y++;
        }
        if (ok)
            break;
    }
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
