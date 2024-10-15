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
int n, m, k, h, q;

map<LL, int> mp;
void solve()
{
    cin >> h >> q;
    // 特殊处理h=1,q=0的情况。
    mp[1ll << (h - 1)] = 0;
    mp[(1ll << h)] = 0;
    for (int i = 1; i <= q; i++)
    {
        int idx, ans;
        LL l, r;
        cin >> idx >> l >> r >> ans;

        r++;
        l <<= (h - idx);
        r <<= (h - idx);
        if (ans == 1)
            mp[l]++, mp[r]--;
        else
        {
            mp[1ll << (h - 1)]++, mp[(1ll << h)]--;
            mp[l]--, mp[r]++;
        }
    }

    LL cur = 0, cnt = 0, start = 0, last = 1ll << (h - 1);
    for (auto &[u, v] : mp)
    {
        if (cur == q)
        {
            cnt += u - last;
            start = last;
        }
        cur += v;
        last = u;
    }

    if (cnt == 0)
        cout << "Game cheated!" << '\n';
    else if (cnt == 1)
        cout << start << '\n';
    else
        cout << "Data not sufficient!" << '\n';
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
