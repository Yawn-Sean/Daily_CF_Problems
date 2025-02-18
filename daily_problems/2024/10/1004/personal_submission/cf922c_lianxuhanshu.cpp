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
LL n, m, k;

void solve()
{
    cin >> n >> k;
    bool ok = true;
    for (int i = 1; i <= k; i++)
    {
        if (n % i != i - 1)
        {
            ok = false;
            break;
        }
    }
    if (ok)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    T = 1;
    while (T--)
    {
        solve();
    }

    return 0;
}
