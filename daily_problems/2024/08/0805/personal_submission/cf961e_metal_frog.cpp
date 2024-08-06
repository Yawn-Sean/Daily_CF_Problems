#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 7;

struct node {
    int l, r;
    int sum;
} tree[N * 33];
int cnt, root[N];
 
void build(int &u, int l, int r) {
    u = ++cnt;
    tree[u].sum = 0;
    if (l == r) return ;
    int mid = (l + r) / 2;
    build(tree[u].l, l, mid);
    build(tree[u].r, mid + 1, r);
}
 
void update(int l, int r, int pre, int &now, int p) {
    tree[++cnt] = tree[pre];
    now = cnt;
    tree[now].sum++; 
    if(l == r) {
        return ;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) {
        update(l, mid, tree[pre].l, tree[now].l, p);
    } else {
        update(mid + 1, r, tree[pre].r, tree[now].r, p);
    }
}
 
int query(int l, int r, int L, int R, int k) {
    if (l == r) {
        return tree[R].sum - tree[L].sum;
    }
    int mid = (l + r) >> 1;
    if (k > mid) {
        return query(mid + 1, r, tree[L].r, tree[R].r, k);
    } else {
        ll ans = tree[tree[R].r].sum - tree[tree[L].r].sum;
        ans += query(l, mid, tree[L].l, tree[R].l, k);
        return ans;
    }
} 

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    build(root[0], 1, n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        x = min(n, x);
        ll inv = query(1, n, root[0], root[min(x, i - 1)], i);
        ans += inv;
        update(1, n, root[i - 1], root[i], x);
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
