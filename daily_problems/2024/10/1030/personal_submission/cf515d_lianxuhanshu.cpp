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
const int N = 2010, mod = 1e9 + 7;
int n, m, k;

char g[N][N];
int cnt[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
char s[] = {'^', '>', 'v', '<'};

void dfs(int x, int y)
{
    for (int k = 0; k < 4; k++)
    {
        int tx = x + dx[k], ty = y + dy[k];
        if (tx <= 0 || tx > n || ty <= 0 || ty > m || g[tx][ty] != '.')
            continue;

        cnt[x][y] = 0;
        cnt[tx][ty] = 0;

        g[x][y] = s[k ^ 2];
        g[tx][ty] = s[k];

        for (int i = 0; i < 4; i++)
        {
            int cx = tx + dx[i], cy = ty + dy[i];
            if (cx <= 0 || cx > n || cy <= 0 || cy > m)
                continue;
            cnt[cx][cy]--;
            if (cnt[cx][cy] == 1)
                dfs(cx, cy);
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> g[i] + 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == '*')
                continue;
            for (int k = 0; k < 4; k++)
            {
                int tx = i + dx[k], ty = j + dy[k];
                if (tx <= 0 || tx > n || ty <= 0 || ty > m || g[tx][ty] == '*')
                    continue;
                cnt[i][j]++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (cnt[i][j] == 1)
                dfs(i, j);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (g[i][j] == '.')
            {
                cout << "Not unique" << '\n';
                return;
            }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << g[i][j];
        cout << '\n';
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
