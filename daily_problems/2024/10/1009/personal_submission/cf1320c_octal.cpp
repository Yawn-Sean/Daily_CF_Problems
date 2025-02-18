#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5+5;
int t[N];
struct info {
    ll maxv;
};
struct tag {
    ll add;
};
info operator + (const info &l, const info &r) {
    info a;
    a.maxv = max(l.maxv, r.maxv);
    return a;
}
info operator + (const info &v, const tag &t) {
    return {v.maxv+t.add};
}
tag operator + (const tag &t1, const tag &t2) {
    return {t1.add + t2.add};
}
struct node {
    tag t;
    info val;
} tr[N * 4];

void update(int id)
{
    tr[id].val = tr[id*2].val + tr[id*2+1].val;
}
void settag(int id, tag t)
{
    tr[id].val = tr[id].val + t;
    tr[id].t = tr[id].t + t;
}
void pushdown(int id)
{
    if(tr[id].t.add != 0) {
        settag(id*2, tr[id].t);
        settag(id*2+1, tr[id].t);
        tr[id].t.add = 0;
    }
}
void build(int id, int l, int r)
{
    if(l == r) 
        tr[id].val = {t[l]};
    else {
        int mid = l+r >> 1;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        update(id);
    }
}
void modify(int id, int l, int r, int ql, int qr, tag t)
{
    if(l == ql && r == qr) {
        settag(id, t);
        return;
    }
    int mid = l+r >> 1;
    pushdown(id);
    if(qr <= mid) modify(id*2, l, mid, ql, qr, t);
    else if(ql > mid) modify(id*2+1, mid+1, r, ql, qr, t);
    else {
        modify(id*2, l, mid, ql, mid, t);
        modify(id*2+1, mid+1, r, mid+1, qr, t);
    }
    update(id);
}
info query(int id, int l, int r, int ql, int qr)
{
    if(l == ql && r == qr) return tr[id].val;
    int mid = l+r >> 1;
    pushdown(id);
    if(qr <= mid) return query(id*2, l, mid, ql, qr);
    else if(ql > mid) return query(id*2+1, mid+1, r, ql, qr);
    else return query(id*2, l, mid, ql, mid) + 
    query(id*2+1, mid+1, r, mid+1, qr);
}


inline void solve()
{
    int n, m, p;
    cin >> n >> m >> p;
    vector<pii> a(n+1);
    vector<pii> b(m+1);
    for(int i=1; i<=n; i++) {
        int va, ca;
        cin >> va >> ca;
        a[i] = {va, ca};
    }
    for(int i=1; i<=m; i++) {
        int vb, cb;
        cin >> vb >> cb;
        b[i] = {vb, cb};
    }
    vector<array<int, 3>> ms(p+1);
    for(int i=1; i<=p; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        ms[i] = {x, y, z};
    }
    sort(a.begin()+1, a.end());
    sort(b.begin()+1, b.end());
    sort(ms.begin()+1, ms.end());
    for(int i=1; i<=m; i++) {
        t[i] = -b[i].second;
    }
    build(1, 1, m);
    ll res = -2e9;
    int idx = 1;
    for(int i=1; i<=n; i++) {
        auto [atk, cost] = a[i];
        while(idx <= p && ms[idx][0] < atk) {
            int l = upper_bound(b.begin()+1, b.end(), (pii){ms[idx][1], 2e9}) - b.begin();
            if(b[l].first > ms[idx][1])
                modify(1, 1, m, l, m, {ms[idx][2]});
            idx ++;
        }
        res = max(res, query(1, 1, m, 1, m).maxv - cost);
    }
    cout << res << endl;
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
