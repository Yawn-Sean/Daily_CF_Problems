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
const int N = 1010, mod = 1e9 + 7;
int n, m, k;

void solve()
{
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (i == j)
                ans ^= x;
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 3)
            cout << ans;
        else
        {
            int x;
            cin >> x;
            ans ^= 1;
        }
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
