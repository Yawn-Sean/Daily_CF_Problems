#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5+5;
int root[N], idx;
struct node {
    int l, r, cnt;
} tr[N << 5];

int build(int l, int r)
{
    int p = ++idx;
    if(l == r) return p;
    int mid = l+r >> 1;
    tr[p].l = build(l, mid);
    tr[p].r = build(mid+1, r);
    return p;
}
int insert(int p, int l, int r, int x)
{
    int q = ++idx;
    tr[q] = tr[p];
    if(l == r) {
        tr[q].cnt ++;
        return q;
    }
    //二分
    int mid = l+r >> 1;
    if(x <= mid) tr[q].l = insert(tr[p].l, l, mid, x);
    else tr[q].r = insert(tr[p].r, mid+1, r, x);

    tr[q].cnt = tr[tr[q].l].cnt + tr[tr[q].r].cnt;
    return q;
}
int query(int q, int p, int l, int r, int k)
{
    if(l == r) return r;
    int cnt = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
    //查询满足cnt >= k 的最小的mid（左边界）
    int mid = l+r >> 1;
    if(k <= cnt) //访问左子树
        return query(tr[q].l, tr[p].l, l, mid, k);
    else //访问右子树
        return query(tr[q].r, tr[p].r, mid+1, r, k-cnt);
}

inline void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    vector<int> b;
    for(int i=1; i<=n; i++)
        b.push_back(i);
    sort(b.begin(), b.end(), [&](int x, int y) {
        if(a[x] != a[y]) return a[x] > a[y];
        return x < y;
    });
    root[0] = build(1, n);
    int i = 1;
    for(int x: b) {
        root[i] = insert(root[i-1], 1, n, x);
        i ++;
    }
    int q;
    cin >> q;
    while(q --) {
        int r, k;
        cin >> r >> k;
        int l = 1;
        cout << a[query(root[r], root[l-1], 1, n, k)] << endl;
    }
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}
