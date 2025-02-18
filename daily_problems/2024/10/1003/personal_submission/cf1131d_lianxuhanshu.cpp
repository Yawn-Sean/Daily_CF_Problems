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
const int N = 1010, mod = 1e9 + 7;
int n, m, k;

char s[N][N];
vector<int> g[N * 2];
int p[N * 2], d[N * 2], q[N * 2], f[N * 2];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

bool top_sort(int cnt)
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n + m; i++)
    {
        if (find(i) != i)
            continue;
        if (!d[i])
            q[++tt] = i, f[i] = 1;
    }

    while (hh <= tt)
    {
        auto t = q[hh++];
        for (auto j : g[t])
        {
            f[j] = max(f[j], f[t] + 1);
            if (--d[j] == 0)
                q[++tt] = j;
        }
    }

    return tt == cnt - 1;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n + m; i++)
        p[i] = i;
    for (int i = 1; i <= n; i++)
        cin >> s[i] + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] == '=')
            {
                int pi = find(i), pj = find(j + n);
                p[pi] = pj;
            }
        }

    for (int i = 1; i <= n; i++)
    {
        int pi = find(i);
        for (int j = 1; j <= m; j++)
        {
            int pj = find(j + n);
            if (s[i][j] == '>')
            {
                g[pj].push_back(pi);
                d[pi]++;
            }
            else if (s[i][j] == '<')
            {
                g[pi].push_back(pj);
                d[pj]++;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n + m; i++)
        if (find(i) == i)
            cnt++;

    bool ok = top_sort(cnt);

    if (ok)
    {
        cout << "Yes" << '\n';
        for (int i = 1; i <= n + m; i++)
            f[i] = f[find(i)];
        for (int i = 1; i <= n; i++)
            cout << f[i] << ' ';
        cout << '\n';
        for (int i = n + 1; i <= n + m; i++)
            cout << f[i] << ' ';
        cout << '\n';
    }
    else
    {
        cout << "No" << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    T = 1;
    while (T--)
    {
        solve();
    }

    return 0;
}
