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

const int maxN = 1000 * 100 + 10;
vector<int> g[maxN]; // 放到里面会RE

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> a(n);
    vector<int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            q.pb(i);
        }
    }

    for (int i = 0; i < q.size(); i++)
    {
        int s = q[i];
        for (auto y : g[s])
        {
            a[y]--;
            if (a[y] == 0)
            {
                q.pb(y);
            }
        }
    }

    cout << q.size() << "\n";
    for (int i = 0; i < q.size(); i++)
    {
        cout << q[i] + 1 << " ";
    }

    return 0;
}
