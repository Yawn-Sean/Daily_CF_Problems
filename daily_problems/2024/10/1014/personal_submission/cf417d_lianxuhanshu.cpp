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
const int N = 110, mod = 1e9 + 7;
int n, m, k, b;

struct Friends
{
    int cost, monster, mask;
} friends[N];
LL f[1 << 20];
void solve()
{
    cin >> n >> m >> b;
    for (int i = 0; i < n; i++)
    {
        int cnt;
        cin >> friends[i].cost >> friends[i].monster >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int x;
            cin >> x;
            friends[i].mask |= (1 << (x - 1));
        }
    }

    sort(friends, friends + n, [&](Friends A, Friends B)
         { return A.monster < B.monster; });

    for (int j = 0; j < 1 << m; j++)
        f[j] = 2e18;
    f[0] = 0;
    LL ans = 2e18;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 1 << m; j++)
        {
            f[j | friends[i].mask] = min(f[j | friends[i].mask], f[j] + friends[i].cost);
        }
        ans = min(ans, f[(1 << m) - 1] + 1ll * friends[i].monster * b);
    }

    if (ans == 2e18)
        ans = -1;
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
