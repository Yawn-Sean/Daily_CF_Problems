/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-06 10:41 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x1, x2;
    cin >> n >> x1 >> x2;
    struct Node {
        LL y1, y2;
        bool operator < (const Node& now) const {
            return y1 < now.y1;
        };
    };
    vector<Node> a(n); 
    struct Tree {
        int l, r;
        LL maxa, mina;
    };
    vector<Tree> tr((n + 1) << 2);
    std::function<void (int, int, int)> build = [&] (int u, int l, int r) -> void {
        if (l == r) {
            tr[u] = {l, r, a[l - 1].y2, a[l - 1].y2};
            return;
        }
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        tr[u].maxa = max(tr[u << 1].maxa, tr[u << 1 | 1].maxa);
        tr[u].mina = min(tr[u << 1].mina, tr[u << 1 | 1].mina);
    };
    std::function<LL (int, int, int)> query_mina = [&] (int u, int l, int r) -> LL {
        if (r < l) return 0x3f3f3f3f3f3f3f3f;
        if (l <= tr[u].l && r >= tr[u].r) {
            return tr[u].mina;
        }
        int mid = tr[u].l + tr[u].r >> 1;
        LL res = 0x3f3f3f3f3f3f3f3f;
        if (l <= mid) res = min(res, query_mina(u << 1, l, r));
        if (r > mid) res = min(res, query_mina(u << 1 | 1, l, r));
        return res;
    };
    std::function<LL (int, int, int)> query_maxa = [&] (int u, int l, int r) -> LL {
        if (r < l) return -0x3f3f3f3f3f3f3f3f;
        if (l <= tr[u].l && r >= tr[u].r) {
            return tr[u].maxa;
        }
        int mid = tr[u].l + tr[u].r >> 1;
        LL res = -0x3f3f3f3f3f3f3f3f;
        if (l <= mid) res = max(res, query_maxa(u << 1, l, r));
        if (r > mid) res = max(res, query_maxa(u << 1 | 1, l, r));
        return res;
    };
    vector<LL> nums;
    for (int i = 0; i < n; i ++) {
        int k, b;
        cin >> k >> b;
        a[i].y1 = 1ll * k * x1 + b;
        a[i].y2 = 1ll * k * x2 + b;
        nums.push_back(a[i].y1); 
    }
    sort(nums.begin(), nums.end());
    int len = unique(nums.begin(), nums.end()) - nums.begin();
    auto find = [&] (LL x) -> int {
        return lower_bound(nums.begin(), nums.begin() + len, x) - nums.begin();
    };
    sort(a.begin(), a.end());
    vector<int> l(len, n + 1), r(len, 0);
    for (int i = 0; i < n; i ++) {
        int f = find(a[i].y1);
        l[f] = min(l[f], i + 1);
        r[f] = max(r[f], i + 1);
    }
    // debug("a:", a);
    build(1, 1, n);
    for (int i = 0; i < len; i ++) {
        LL maxa = query_maxa(1, 1, l[i] - 1);
        LL mina = query_mina(1, r[i] + 1, n);
        LL x = query_maxa(1, l[i], r[i]);
        LL y = query_mina(1, l[i], r[i]);
        if (maxa > y || mina < x) {
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
    return 0;
}

#endif

/*

*/
