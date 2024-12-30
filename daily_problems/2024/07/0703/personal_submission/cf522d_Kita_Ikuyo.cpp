#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long

#ifdef LOCAL
#include "C:\Program Files\DEBUG\debug.h"
#else
#define debug(...) 114514
#define ps 114514
#endif
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
const int N = 5e5 + 10;
const int inf = 1e12;

int min1[4 * N];
int n;

void push_up(int p) {
    min1[p] = min(min1[ls(p)], min1[rs(p)]);
}

void build(int p, int l, int r) {
    if (l == r) {
        min1[p] = inf;
        return;
    }
    int mid = (l + r) / 2;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    push_up(p);
}

void modify(int pos, int k, int l = 1, int r = n, int p = 1) {
    if (l == r) {
        min1[p] = k;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        modify(pos, k, l, mid, ls(p));
    else
        modify(pos, k, mid + 1, r, rs(p));
    push_up(p);
}
int querymin(int x, int y, int l = 1, int r = n, int p = 1) {
    int res = inf;
    if (x <= l && y >= r) {
        return min1[p];
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        res = min(res, querymin(x, y, l, mid, ls(p)));
    if (y > mid)
        res = min(res, querymin(x, y, mid + 1, r, rs(p)));
    return res;
}

struct node {
    int l;
    int r;
    int id;
};

signed main() {
    int m;
    IOS cin >> n >> m;
    vector<int> a(n + 1);
    map<int, int> mp;
    vector<node> query(m + 1);
    vector<int> ans(m + 1);
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> query[i].l >> query[i].r;
        query[i].id = i;
    }
    sort(query.begin() + 1, query.begin() + m + 1,
         [&](node a, node b) { return a.r < b.r; });
    int r = 0;
    for (int i = 1; i <= m; i++) {
        while (r < query[i].r) {
            r++;
            if (!mp[a[r]]) {
                mp[a[r]] = r;
                continue;
            } else {
                modify(mp[a[r]], r - mp[a[r]]);
                mp[a[r]] = r;
            }
        }
        if (querymin(query[i].l, query[i].r) == inf)
            ans[query[i].id] = -1;
        else
            ans[query[i].id] = querymin(query[i].l, query[i].r);
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
