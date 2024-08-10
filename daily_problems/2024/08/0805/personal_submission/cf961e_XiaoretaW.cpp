using LL = long long;
const int maxn = 2e5 + 5;
struct Node{
    LL info;
    int l, r;
}tr[maxn * 64];
int root[maxn];
int idx;
 
void modify_from(int &now, int pre, int l, int r, int x){
    tr[now = ++idx] = tr[pre];
    if (l == r){
        tr[now].info += 1;
        return;
    }
    int mid = (l + r) / 2;
    if (x < mid) modify_from(tr[now].l, tr[pre].l, l, mid, x);
    else modify_from(tr[now].r, tr[pre].r, mid + 1, r, x);
    tr[now].info = tr[tr[now].l].info + tr[tr[now].r].info;
}
 
LL query(int root1, int root2, int l, int r, int L, int R){
    if (r < L || l > R){
        return 0;
    }
    if (l >= L && r <= R){
        return tr[root2].info - tr[root1].info;
    }
    int mid = (l + r) / 2;
    return query(tr[root1].l, tr[root2].l, l, mid, L, R) + query(tr[root1].r, tr[root2].r, mid + 1, r, L, R);
}
 
 
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
 
    const int N = 1e9;
 
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        setmin(a[i], n);
        modify_from(root[i], root[i - 1], 0, N, a[i]);
    }
 
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = min(i - 1, a[i]);
        if (r < l) continue;
        ans += (r - l + 1) - query(root[l - 1], root[r], 0, N, 0, i);
    }
 
    cout << ans << '\n';
 
 
    return 0;
}
