/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-03 17:17 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 512345;

int a[N], ne[N], fr[N], dis[N], now[N];
int n, m;
int len;
vector<std::pair<int, int>> vii[N];
vector<int> nums;
int ans[N];

struct Node {
    int l, r;
    int mina;
} tr[N << 2];

int find(int x) {
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

void pushup(int u) {
    tr[u].mina = min(tr[u << 1].mina, tr[u << 1 | 1].mina);
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = {l, r, dis[l]};
        return;
    }
    int mid = l + r >> 1;
    tr[u] = {l, r};
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int x) {
    if (tr[u].l == tr[u].r) {
        tr[u].mina = x;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, x);
    else modify(u << 1 | 1, l, x);
    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && r >= tr[u].r) return tr[u].mina;
    int res = n + 1;
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) res = min(query(u << 1, l, r), res);
    if (r > mid) res = min(query(u << 1 | 1, l, r), res);
    return res; 
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        nums.push_back(a[i]);
    }
    sort(nums.begin(), nums.end());
    for (int i = 1; i <= n; i ++) {
        int j = find(a[i]);
        fr[i] = now[j];
        dis[i] = i - fr[i];
        if (fr[i] == 0) dis[i] = n + 1;
        now[j] = i;
    }
    for (int i = 0; i < nums.size(); i ++) now[i] = 0;
    for (int i = n; i; i --) {
        int j = find(a[i]);
        ne[i] = now[j];
        now[j] = i;
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i ++) {
        int l, r;
        cin >> l >> r;
        vii[l].push_back({r, i});
    }
    for (int i = 1; i <= n; i ++) {
        if (vii[i].size()) {
            sort(vii[i].begin(), vii[i].end());
            for (int j = 0; j < vii[i].size(); j ++) {
                ans[vii[i][j].second] = query(1, 1, vii[i][j].first);
                if (ans[vii[i][j].second] == n + 1) ans[vii[i][j].second] = -1;
            }
        }
        if (ne[i]) {
            modify(1, ne[i], n + 1);
        }
    }
    for (int i = 1; i <= m; i ++) cout << ans[i] << "\n";
    return 0;
}

/*

*/
