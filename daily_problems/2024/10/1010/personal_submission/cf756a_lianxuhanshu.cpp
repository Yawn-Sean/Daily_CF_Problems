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

int p[N];
bool vis[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            int v = i;
            while (!vis[v])
            {
                vis[v] = true;
                v = p[v];
            }
            cnt++;
        }

    if (cnt == 1)
        cnt--;

    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        int b;
        cin >> b;
        num += b;
    }

    if (num % 2 == 0)
        cnt++;
    cout << cnt << '\n';
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
