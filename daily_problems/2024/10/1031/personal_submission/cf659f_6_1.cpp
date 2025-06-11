#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

const int N = 1e3 + 10;
int a[N][N], nums[N][N];
pii p[N][N];

pii find(int x, int y)
{
    if (p[x][y] == (pii){x, y})
        return {x, y};
    else
        return p[x][y] = find(p[x][y].first, p[x][y].second);
}

void merge(int x, int y, int x2, int y2)
{
    pii a = find(x, y);
    pii b = find(x2, y2);
    if (a != b)
    {
        p[a.first][a.second] = b;
        nums[b.first][b.second] += nums[a.first][a.second];
    }
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    set<int> s;
    vector<int> v;
    map<int, int> ma;
    auto ok = [&](int x) -> bool
    { return x <= n && x >= 1; };
    auto ok1 = [&](int x) -> bool
    { return x <= m && x >= 1; };
    auto search = [&](int x, int y) -> void
    {
        if (ok(x + 1) && a[x + 1][y] >= a[x][y])
            merge(x, y, x + 1, y);
        if (ok(x - 1) && a[x - 1][y] >= a[x][y])
            merge(x, y, x - 1, y);
        if (ok1(y + 1) && a[x][y + 1] >= a[x][y])
            merge(x, y, x, y + 1);
        if (ok1(y - 1) && a[x][y - 1] >= a[x][y])
            merge(x, y, x, y - 1);
    };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            s.insert(a[i][j]);
            nums[i][j] = 1;
            p[i][j] = {i, j};
        }
    }
    int idx = 0;
    for (auto x : s)
        v.push_back(x), ma[x] = idx++;
    vector<vector<pii>> vv(idx);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = ma[a[i][j]];
            vv[a[i][j]].push_back({i, j});
        }
    }
    vector<vector<int>> ans(n + 1, vector<int>(m + 1, 0));
    int num1 = 0;
    auto get = [&](auto &&get, int x, int y, int c) -> void
    {
        if (num1 == 0 || ans[x][y] != 0)
            return;
        ans[x][y] = c, num1--;
        // cout << "num11=" << num11 << endl;
        if (ok(x + 1) && v[a[x + 1][y]] >= c)
            get(get, x + 1, y, c);
        if (ok(x - 1) && v[a[x - 1][y]] >= c)
            get(get, x - 1, y, c);
        if (ok1(y + 1) && v[a[x][y + 1]] >= c)
            get(get, x, y + 1, c);
        if (ok1(y - 1) && v[a[x][y - 1]] >= c)
            get(get, x, y - 1, c);
    };
    for (int i = idx - 1; i >= 0; i--)
    {
        for (auto [x, y] : vv[i])
        {
            search(x, y);
            pii aa = find(x, y);
            int num = nums[aa.first][aa.second] * v[a[x][y]];
            if (num - k >= 0 && (num - k) % v[a[x][y]] == 0)
            {
                cout << "YES\n";
                num1 = k / v[a[x][y]];
                // cout << "num11=" << num11 << endl;
                // cout << "x=" << x <<"y="<<y<< endl;
                get(get, x, y, v[a[x][y]]);
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= m; j++)
                        cout << ans[i][j] << ' ';
                    cout << endl;
                }
                return;
            }
        }
    }
    cout << "NO\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    while (tt--)
    {
        solve();
    }
}
