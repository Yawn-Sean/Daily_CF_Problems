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

const int N = 110;

int a[N][N];
int init(int x, int y)
{
    for (int i = 1; i <= 148; i++)
        if (a[x - 1][y] != i && a[x + 1][y] != i && a[x][y - 1] != i && a[x][y + 1] != i)
            return i;
    return 148;
}
signed main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 0)
            {
                int b = init(i, j);
                int c = 1;
                while (i + c <= n && j + c <= m && a[i][j + c] == 0 && init(i, j + c) == b)
                    c++;
                for (int x = 0; x < c; x++)
                    for (int y = 0; y < c; y++)
                    {
                        a[x + i][y + j] = b;
                    }
            }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            printf("%c", a[i][j] + 'A' - 1);
            if (j == m)
                printf("\n");
        }
    return 0;
}
