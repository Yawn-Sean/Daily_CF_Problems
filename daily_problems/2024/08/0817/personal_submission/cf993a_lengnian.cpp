#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using i128 = __int128;
using ull = unsigned long long;
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define pqi priority_queue<int> // 优先队列

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long

int ax[5], ay[5], bx[5], by[5];
bool st[205][205];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 4; i++)
        cin >> ax[i] >> ay[i];
    for (int i = 1; i <= 4; i++)
        cin >> bx[i] >> by[i];

    sort(ax + 1, ax + 4 + 1);
    sort(ay + 1, ay + 4 + 1);
    sort(bx + 1, bx + 4 + 1);
    sort(by + 1, by + 4 + 1);

    unique(ax + 1, ax + 4 + 1);
    unique(ay + 1, ay + 4 + 1);
    unique(bx + 1, bx + 4 + 1);
    unique(by + 1, by + 4 + 1);
    for (int x = ax[1]; x <= ax[2]; x++)
        for (int y = ay[1]; y <= ay[2]; y++)
            st[x + 100][y + 100] = true;
    int cenx = bx[2], ceny = by[2], len = bx[2] - bx[1];
    for (int i = -100; i <= 100; i++)
        for (int j = -100; j <= 100; j++)
            if (abs(i - cenx) + abs(j - ceny) <= len)
                if (st[i + 100][j + 100])
                {
                    puts("YES");
                    return 0;
                }
    puts("NO");
    return 0;
}
