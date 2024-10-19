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
int h, n, m, k;

void solve()
{
    cin >> h >> m >> n;

    vector<int> group_id(h, -1), group_pos(h, -1);
    int k1 = 0, k2 = 0;
    for (int i = 0; i < h; i++)
    {
        if (group_id[i] == -1)
        {
            k2 = 0;
            while (group_id[i] == -1)
            {
                group_id[i] = k1;
                group_pos[i] = k2;
                i = (i + m) % h;
                k2++;
            }
            k1++;
        }
    }

    vector<set<int>> groups(k1);
    for (int i = 0; i < k1; i++)
        for (int j = 0; j < k2; j++)
            groups[i].insert(j);

    map<int, int> mp;

    LL ans = 0;
    while (n--)
    {
        char op[2];
        cin >> op;
        if (op[0] == '+')
        {
            int idx, hash_v;
            cin >> idx >> hash_v;
            int g_id = group_id[hash_v], g_pos = group_pos[hash_v], v = -g_pos;
            if (*groups[g_id].rbegin() >= g_pos)
                g_pos = *groups[g_id].lower_bound(g_pos);
            else
                g_pos = *groups[g_id].begin();
            v += g_pos;
            if (v < 0)
                v += k2;

            ans += v;

            groups[g_id].erase(g_pos);
            mp[idx] = g_id * k2 + g_pos;
        }
        else
        {
            int idx;
            cin >> idx;
            int g_id = mp[idx] / k2, g_pos = mp[idx] % k2;
            groups[g_id].insert(g_pos);
        }
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
