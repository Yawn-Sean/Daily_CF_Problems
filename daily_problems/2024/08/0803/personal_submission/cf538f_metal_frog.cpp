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
} tree[N << 7];
int cnt, root[N << 1];
 
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
    if (k <= mid) {
        return query(l, mid, tree[L].l, tree[R].l, k);
    } else {
        ll ans = tree[tree[R].l].sum - tree[tree[L].l].sum;
        ans += query(mid + 1, r, tree[L].r, tree[R].r, k);
        return ans;
    }
} 
 
void solve() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    vector<int> tmp = num;
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());
 
    build(root[0], 1, n);
    for (int i = 0; i < n; i++) {
        num[i] = lower_bound(all(tmp), num[i]) - tmp.begin() + 2;
        update(1, n, root[i], root[i + 1], num[i]);
    }
    for (int k = 1; k <= n - 1; k++) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int v = num[i - 1];
            int l = k * (i - 1) + 2, r = min(n, k * i + 1);
            if (l > n) break;
            ans += query(1, n, root[l - 1], root[r], v - 1);
        }
        cout << ans << " ";
    }
    cout << "\n";
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
