#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = -1e18;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
int ans;

void solve()
{
    int n;
    cin >> n;
    vector<int> x(n + 1, 0), y(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    int m;
    cin >> m;
    vector<int> stk, dep(n + 1, 0);
    stk.push_back(n);
    vector<vector<int>> nex(20, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 1; i--)
    {
        while (stk.size() >= 2)
        {
            int p2 = stk[stk.size() - 2], p1 = stk.back();
            if ((y[p1] - y[i]) * (x[p2] - x[i]) < (y[p2] - y[i]) * (x[p1] - x[i]))
                stk.pop_back();
            else
                break;
        }
        nex[0][i] = stk.back();
        dep[i] = dep[stk.back()] + 1;
        stk.push_back(i);
    }
    nex[0][n] = n;
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            nex[i][j] = nex[i - 1][nex[i - 1][j]];
        }
    }
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (dep[a] < dep[b])
            swap(a, b);
        for (int i = 19; i >= 0; i--)
        {
            if (dep[nex[i][a]] >= dep[b])
            {
                a = nex[i][a];
            }
        }
        if (a == b)
        {
            cout << a << ' ';
        }
        else
        {
            for (int i = 19; i >= 0; i--)
            {
                if (nex[i][a] != nex[i][b])
                {
                    a = nex[i][a];
                    b = nex[i][b];
                }
            }
            cout << nex[0][a] << ' ';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}