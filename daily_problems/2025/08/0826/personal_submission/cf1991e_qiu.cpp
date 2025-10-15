#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005, mod = 998244353;

vector<int> e[N];
int col[N];
bool dfs(int u, int c)
{
    col[u] = c;
    for (auto v : e[u])
    {
        if (!col[v])
        {
            if (!dfs(v, 3 - c))
                return false;
        }
        else if (col[v] == c)
            return false;
    }
    return true;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        e[i].clear();
        col[i] = 0;
    }
    vector<PII> ve;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ve.push_back({u, v});
    }
    if (dfs(1, 1))
    {
        cout << "Bob" << endl;
        vector<int> vis(n + 1, 0);
        queue<int> q1, q2;
        for (int i = 1; i <= n; i++)
        {
            if (col[i] == 1)
            {
                q1.push(i);
            }
            else
                q2.push(i);
        }

        for (int i = 1; i <= n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (a > b)
                swap(a, b);
            if (a == 1)
            {
                if (!q1.empty())
                {
                    auto t = q1.front();
                    q1.pop();
                    cout << t << ' ' << 1 << endl;
                }
                else if (b == 2)
                {
                    if (!q2.empty())
                    {
                        auto t = q2.front();
                        q2.pop();
                        cout << t << ' ' << 2 << endl;
                    }
                }
                else
                {

                    auto t = q2.front();
                    q2.pop();
                    cout << t << ' ' << 3 << endl;
                }
            }
            else
            {
                if (!q2.empty())
                {
                    auto t = q2.front();
                    q2.pop();
                    cout << t << ' ' << 2 << endl;
                }
                else
                {
                    auto t = q1.front();
                    q1.pop();
                    cout << t << ' ' << 3 << endl;
                }
            }
        }
    }
    else
    {
        cout << "Alice" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << 1 << ' ' << 2 << endl;
            int a, b;
            cin >> a >> b;
        }
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T = 1;

    cin >> T;
    while (T--)
        solve();
    // cout << idx << endl;
    return 0;
}
