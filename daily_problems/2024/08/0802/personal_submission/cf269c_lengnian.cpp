#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;
struct Edge
{
    int nt, v, c, val;
} e[400010];
int st[N];
int n, m, f[N], q[N];

void addedge(int k, int a, int b, int c)
{
    e[k].v = b;
    e[k].c = c;
    e[k].val = -1;
    e[k].nt = st[a];
    st[a] = k;
}

void bfs()
{
    int hd = 0, tl = 0;
    for (int i = 1; i <= n; i++)
        if (f[i] == 0)
        {
            tl++;
            q[tl] = i;
        }
    while (hd < tl)
    {
        hd++;
        int k = st[q[hd]];
        while (k)
        {
            if (e[k].val == -1)
            {
                e[k].val = 0;
                if (k % 2 == 1)
                    e[k + 1].val = 1;
                else
                    e[k - 1].val = 1;
                f[e[k].v] -= e[k].c;
                if (f[e[k].v] == 0)
                {
                    tl++;
                    q[tl] = e[k].v;
                }
            }
            k = e[k].nt;
        }
    }
}

int main()
{

    cin >> n >> m;
    memset(st, 0, sizeof(st));
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        addedge(i * 2 - 1, a, b, c);
        addedge(i * 2, b, a, c);
        if (a > 1)
            f[a] += c;
        if (b > 1)
            f[b] += c;
    }
    for (int i = 2; i < n; i++)
        f[i] /= 2;
    bfs();
    for (int i = 1; i < 2 * m; i += 2)
        cout << e[i].val << "\n";
    return 0;
}
