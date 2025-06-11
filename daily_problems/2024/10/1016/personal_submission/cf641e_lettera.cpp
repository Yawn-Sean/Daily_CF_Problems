 #include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
bool cmp(array<int, 5> a, array<int, 5> b)
{
    if (a[3] != b[3])
    {
        return a[3] < b[3];
    }
    else
    {
        return a[0] < b[0];
    }
}
const int N = 1E5 + 5;
int bit[N];
void ins(int x, int y)
{
    for (int i = x; i < N; i += i & -i)
    {
        bit[i] += y;
    }
}
int query(int x)
{
    if (!x)
    {
        return 0;
    }
    int ret = 0;
    for (int i = x; i; i -= i & -i)
    {
        ret += bit[i];
    }
    return ret;
}
int query(int l, int r)
{
    return query(r) - query(l - 1);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n + 1);
    vector<array<int, 5>> a(n + 1);
    vector<int> tmp1;
    vector<int> tmp2;
    int top = 1;
    for (int i = 1; i <= n; i++)
    {
        a[i][0] = i;
        for (int j = 1; j <= 3; j++)
        {
            cin >> a[i][j];
        }
        if (a[i][1] == 3)
        {
            a[i][4] = top++;
        }
        tmp1.push_back(a[i][3]);
        tmp2.push_back(a[i][2]);
    }
    sort(tmp1.begin(), tmp1.end());
    sort(tmp2.begin(), tmp2.end());
    int len = unique(tmp1.begin(), tmp1.end()) - tmp1.begin();
    for (int i = 1; i <= n; i++)
    {
        a[i][3] = lower_bound(tmp1.begin(), tmp1.begin() + len, a[i][3]) - tmp1.begin() + 1;
        a[i][2] = lower_bound(tmp2.begin(), tmp2.end(), a[i][2]) - tmp2.begin() + 1;
    }
    sort(a.begin() + 1, a.end(), cmp);
    vector<array<int, 2>> c;
    for (int i = 1; i <= n; i++)
    {
        if (a[i][3] != a[i - 1][3])
        {
            for (auto [x, y] : c)
            {
                ins(x, -y);
            }
            c.clear();
        }
        if (a[i][1] == 1)
        {
            ins(a[i][2], 1);
            c.push_back({a[i][2], 1});
        }
        else if (a[i][1] == 2)
        {
            ins(a[i][2], -1);
            c.push_back({a[i][2], -1});
        }
        else
        {
            ans[a[i][4]] = query(a[i][2]);
        }
    }

    for (int i = 1; i < top; i++)
    {
        cout << ans[i] << "\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
