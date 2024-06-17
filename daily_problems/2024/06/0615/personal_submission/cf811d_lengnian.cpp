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
// #define int long long

const int N = 100;
int a[N][N], b[N][N], p[N][N];
int f[4] = {0, 1, 2, 3}, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char dc[4] = {'D', 'R', 'U', 'L'};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int fx, fy;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c == '*';
            if (c == 'F')
                fx = i, fy = j;
            else
                b[i][j] = -1;
            p[i][j] = -1;
        }

    queue<pair<int, int>> q;
    q.push({fx, fy});
    while (!q.empty())
    {
        int bx = q.front().fi, by = q.front().se;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = bx + dx[i], y = by + dy[i];
            if (x >= 0 && y >= 0 && x < n && y < m && !a[x][y] && !~b[x][y])
            {
                b[x][y] = b[bx][by] + 1, p[x][y] = (i + 2) % 4, q.push({x, y});
            }
        }
    }

    for (int i = 0, j = 0, x, y; i != fx || j != fy; i = x, j = y)
    {
        int z = p[i][j];
        cout << dc[f[z]] << endl;
        cin >> x >> y;
        x--, y--;
        if (x == i && y == j)
        {
            swap(f[z], f[(z + 2) % 4]);
            cout << dc[f[z]] << endl;
            cin >> x >> y;
            x--, y--;
        }
    }

    return 0;
}
