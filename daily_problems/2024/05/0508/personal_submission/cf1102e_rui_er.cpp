typedef Modint<998244353> mint;
const int N = 2e5 + 5;

int n, a[N], b[N], m, l[N], r[N], rt[N], ans;
int find(int x) {return x == rt[x] ? x : rt[x] = find(rt[x]);}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) b[++m] = a[i];
    sort(b + 1, b + 1 + m);
    m = unique(b + 1, b + 1 + m) - b - 1;
    rep(i, 1, n) a[i] = lower_bound(b + 1, b + 1 + m, a[i]) - b;
    rep(i, 1, n) r[a[i]] = i;
    per(i, n, 1) l[a[i]] = i;
    rep(i, 1, n) rt[i] = i;
    rep(i, 1, m) for(int u = find(l[i]); u < r[i]; u = find(u)) rt[u] = u + 1;
    rep(i, 1, n) if(rt[i] == i) ++ans;
    cout << (mint(2) ^ (ans - 1)) << endl;
    return 0;
}
