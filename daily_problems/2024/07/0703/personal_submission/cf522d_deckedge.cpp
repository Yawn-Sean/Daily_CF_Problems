#include <bits/stdc++.h>
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid (l + r >> 1)
#define lson ls, l, mid
#define rson rs, mid + 1, r
#define rep(i, a, b) for (int i = a; i < b; i++)
const int maxn = 2e6 + 10;
const int inf = 1e9;
int a[maxn], b[maxn], n, m, res[maxn];
map<int, int> mp;
struct p {
    int l, r, id;
    bool operator < (const p&tmp )  const {
        return r < tmp.r;
    }
}f[maxn]; 
int top = 1;
void update(int rt, int l, int r, int u, int val) {
    if (l == r && l == u) { 
        a[rt] = val;
        return; 
    }
    if (r < u || l > u) {
        return;
    }
    update(lson, u, val);
    update(rson, u, val);
    a[rt] = min(a[ls], a[rs]);
}
int ask(int rt, int l, int r, int L, int R) {
    if (l >= L && r <= R) {
        return a[rt];
    }
    if (r < L || l > R) {
        return inf;
    }
    return min(ask(lson, L, R), ask(rson, L, R));
}
int main() {
    cin >> n >> m;
    rep(i, 1, 4 * n + 1) {
        a[i] = inf;//线段树初始化
    }
    rep(i, 1, n + 1) {
        cin >> b[i];
    }
    rep(i, 1, m + 1) {
        cin >> f[i].l >> f[i].r;
        f[i].id = i;
    }
    sort(f + 1, f + 1 + m);
    rep(i, 1, n + 1) {
        if (mp[b[i]]) {
            update(1, 1, n, mp[b[i]], i - mp[b[i]]);
        }
        while (top <= m && i == f[top].r) {
            res[f[top].id] = ask(1, 1, n, f[top].l, f[top].r);
            top++;
        }
        mp[b[i]] = i; 
    }
    rep(i, 1, m + 1) {
        cout << (res[i] == inf ? -1 : res[i]) << '\n'; 
    }
}
