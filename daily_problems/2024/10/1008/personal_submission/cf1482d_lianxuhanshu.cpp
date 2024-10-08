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
const int N = 1e5 + 10, mod = 1e9 + 7;
int n, m, k;

int a[N];
int ne[N], la[N];
bool del[N];

int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        del[i] = false;
        ne[i] = i + 1;
        la[i] = i - 1;
    }
    la[1] = n;
    ne[n] = 1;

    queue<PII> q;
    for (int i = 1; i <= n; i++)
    {
        if (i < n)
            q.push({i, i + 1});
        else
            q.push({n, 1});
    }

    vector<int> ans;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        int u = t.first, v = t.second;
        if (del[u])
            continue;
        if (gcd(a[u], a[v]) == 1)
        {
            del[v] = true;
            ans.push_back(v);
            if (u != v)
            {
                ne[u] = ne[v];
                la[ne[v]] = u;
                q.push({u, ne[u]});
            }
        }
    }

    cout << ans.size() << ' ';
    for (auto &v : ans)
        cout << v << ' ';
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
