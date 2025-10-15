#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

int n, m;
const int N = 110;
char g[N][N];
bool vis[N][N];
vector<tuple<int, int, int>> res;

bool in(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

bool can(int x, int y, int d)
{
    return in(x - d, y) && in(x + d, y) && in(x, y - d) && in(x, y + d) &&
           g[x - d][y] == '*' && g[x + d][y] == '*' &&
           g[x][y - d] == '*' && g[x][y + d] == '*';
}

int main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", g[i] + 1);
        // cout << g[i] << endl;
    }

    for (int i = 2; i < n; i++)
    {
        for (int j = 2; j < m; j++)
        {
            if (g[i][j] != '*')
                continue;
            int d = 1;
            while (can(i, j, d))
                d++;
            d--;
            if (d > 0)
            {
                res.push_back({i, j, d});
                vis[i][j] = true;
                for (int k = 1; k <= d; k++)
                {
                    vis[i - k][j] = true;
                    vis[i + k][j] = true;
                    vis[i][j - k] = true;
                    vis[i][j + k] = true;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (g[i][j] == '*' && !vis[i][j])
            {
                cout << -1 << '\n';
                return 0;
            }

    cout << res.size() << '\n';
    for (auto [x, y, s] : res)
    {
        cout << x << ' ' << y << ' ' << s << '\n';
    }

    return 0;
}
