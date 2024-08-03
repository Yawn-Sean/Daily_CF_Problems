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
const int N = 300, M = 150;
int g[N][N];
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    queue<pii> q;
    int t;
    cin >> g[M][M] >> t;
    if (g[M][M] > 3)
    {
        q.push({M, M});
    }

    while (q.size())
    {
        int s = q.size();
        while (s--)
        {
            pii t = q.front();
            q.pop();
            if (g[t.fi][t.se] > 3)
            {
                int v = g[t.fi][t.se] / 4;
                for (int i = 0; i < 4; i++)
                {
                    g[t.fi + d[i][0]][t.se + d[i][1]] += v;
                    if (g[t.fi + d[i][0]][t.se + d[i][1]] > 3)
                    {
                        q.push({t.fi + d[i][0], t.se + d[i][1]});
                    }
                }
                g[t.fi][t.se] %= 4;
            }
        }
    }

    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (x >= M || y >= M || x < -M || y < -M)
        {
            cout << "0\n";
        }
        else
        {
            cout << g[x + M][y + M] << "\n";
        }
    }
    return 0;
}
