
struct node
{
    int l, r, sum, num;
} e[N << 1], use;
node operator+(node a, node b)
{
    node x;
    x.num = a.num + b.num;
    x.sum = a.sum + b.sum;
    return x;
}
int rt, tot;
void push(int p)
{
    e[p].sum = e[e[p].l].sum + e[e[p].r].sum;
    e[p].num = e[e[p].l].num + e[e[p].r].num;
}
void insert(int &p, int l, int r, int pos, int val)
{
    if (!p)
        p = ++tot;
    if (l == r)
    {
        e[p].num += val;
        e[p].sum = e[p].num * pos;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        insert(e[p].l, l, mid, pos, val);
    else
        insert(e[p].r, mid + 1, r, pos, val);
    push(p);
}
node ask(int p, int L, int R, int l, int r)
{
    if (!p)
        return use;
    if (L <= l && r <= R)
        return e[p];
    int mid = (l + r) >> 1;
    node ans;
    ans.sum = ans.num = 0;
    if (L <= mid)
        ans = ans + ask(e[p].l, L, R, l, mid);
    if (mid < R)
        ans = ans + ask(e[p].r, L, R, mid + 1, r);
    return ans;
}
int id(double x)
{
    int y = ceil(x);
    return min(1e10, x);
}
bool check(double mid, double sum)
{
    node ans = ask(rt, 0, id(mid), 0, 1e10);
    double cnt = (double)ans.num * mid - (double)ans.sum;
    return cnt >= sum;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a[N];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        insert(rt, 0, 1e10, a[i], 1);
    }
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, x;
            cin >> l >> x;
            insert(rt, 0, 1e10, a[l], -1);
            a[l] = x;
            insert(rt, 0, 1e10, a[l], 1);
        }
        else
        {
            double x;
            cin >> x;
            double l = 0, r = 1e15;
            double ans = 0;
            while (r - l > eps)
            {
                double mid = (l + r) / 2.0;
                if (check(mid, x))
                    ans = mid, r = mid;
                else
                    l = mid;
            }
            cout << fixed << setprecision(5) << ans << endl;
        }
    }
    return 0;
}
