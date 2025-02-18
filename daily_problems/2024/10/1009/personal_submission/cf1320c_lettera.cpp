#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const int N = 2e5 + 5;
int val[N << 1], lson[N << 1], rson[N << 1], tag[N << 1], root, id;
// val[l,r]表示离散化后的防护力[l,r]的防具的最大收益
// 我们需要执行区间加和求区间最大值操作
void build(int &now, int l, int r)
{
    val[now] = 0;
    if (!now)
    {
        now = ++id;
    }
    if (l == r)
    {
        return;
    }
    int mid = l + (r - l) / 2;
    build(lson[now], l, mid);
    build(rson[now], mid + 1, r);
}
void update(int now, int l, int r, int L, int R, int x)
{
    if (l > R || r < L)
    {
        return;
    }
    if (l >= L && r <= R)
    {
        val[now] += x;
        tag[now] += x;
        return;
    }
    if (tag[now] && l < r)
    {
        val[lson[now]] += tag[now];
        val[rson[now]] += tag[now];
        tag[lson[now]] += tag[now];
        tag[rson[now]] += tag[now];
        tag[now] = 0;
    }
    int mid = l + (r - l) / 2;
    update(lson[now], l, mid, L, R, x);
    update(rson[now], mid + 1, r, L, R, x);
    val[now] = max(val[lson[now]], val[rson[now]]);
}
void solve()
{
    // 先按照攻击力升序枚举攻击道具
    // 随攻击力增加单指针右移增加怪兽
    // 每加一只怪兽,增加相应的防具的收益
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n + 1), b(n + 1), c(m + 1), d(m + 1), x(p + 1), y(p + 1), z(p + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> c[i] >> d[i];
    }
    for (int i = 1; i <= p; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
    }
    vector<int> tmp(m + 1);
    tmp = c;
    sort(tmp.begin() + 1, tmp.end());
    int len = unique(tmp.begin() + 1, tmp.end()) - tmp.begin() - 1;
    vector<int> cost(len + 1, 1E18); //[l,l]防具的最小成本
    map<int, int> mp;
    for (int i = 1; i <= len; i++)
    {
        mp[tmp[i]] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cost[mp[c[i]]] = min(cost[mp[c[i]]], d[i]);
    }
    build(root, 1, len);
    for (int i = 1; i <= len; i++)
    {
        //[i,i]加上-cost[i]
        update(root, 1, len, i, i, -cost[i]);
    }
    int ans = -1E18;
    vector<int> id1(n + 1), id2(p + 1);
    iota(id1.begin() + 1, id1.end(), 1);
    iota(id2.begin() + 1, id2.end(), 1);
    sort(id1.begin() + 1, id1.end(), [&](int x, int y) { return a[x] < a[y]; });
    sort(id2.begin() + 1, id2.end(), [&](int i, int j) { return x[i] < x[j]; });
    int pos = 1;
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = id1[i];
        while (pos <= p && a[k] > x[id2[pos]])
        {
            //[y[id2[pos]]+1,inf]区间的防具收益加z[id2[pos]]
            int l = lower_bound(tmp.begin() + 1, tmp.begin() + len + 1, y[id2[pos]] + 1) - tmp.begin();
            if (l <= len)
            {
                update(root, 1, len, l, len, z[id2[pos]]);
            }
            pos++;
        }
        ans = max(ans, val[root] - b[k]);
    }
    cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
