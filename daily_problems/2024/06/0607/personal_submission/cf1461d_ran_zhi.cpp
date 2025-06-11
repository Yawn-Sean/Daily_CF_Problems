#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

vector<int> arr;
class SegmentTree {
public :
    struct Data {
        Data(int l = 0, int r = 0, int maxn = 0, int minn = 0, ll sum = 0) 
            : l(l), r(r), maxn(maxn), minn(minn), sum(sum) {}
        int l, r, maxn, minn;
        ll sum;
    };

    vector<Data> tr;

    SegmentTree (int t) : tr(t + 10 << 2) {}

    void push_up(int u) {
        Data &root = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
        root.maxn = max(l.maxn, r.maxn);
        root.minn = min(l.minn, r.minn);
        root.sum = l.sum + r.sum;
        return;
    }

    void buildtree(int u, int l, int r) {
        tr[u].l = l, tr[u].r = r;
        if (l == r) {
            tr[u].maxn = tr[u].minn = tr[u].sum = arr[r];
            return;
        }
        int mid = l + r >> 1;
        buildtree(u << 1, l, mid);
        buildtree(u << 1 | 1, mid + 1, r);
        push_up(u);
        return;
    }

    int query_min(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u].minn;
        int mid = tr[u].l + tr[u].r >> 1;
        int v = INT_MAX;
        if (l <= mid) v = query_min(u << 1, l, r);
        if (r > mid) v = min(v, query_min(u << 1 | 1, l, r));
        return v;
    }

    int query_max(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u].maxn;
        int mid = tr[u].l + tr[u].r >> 1;
        int v = INT_MIN;
        if (l <= mid) v = query_max(u << 1, l, r);
        if (r > mid) v = max(v, query_max(u << 1 | 1, l, r));
        return v;
    }

    ll query_val(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
        int mid = tr[u].l + tr[u].r >> 1;
        ll sum = 0;
        if (l <= mid) sum = query_val(u << 1, l, r);
        if (r > mid) sum += query_val(u << 1 | 1, l, r);
        return sum;
    }

    unordered_set<ll> s;
    void get_num(int l, int r) {
        s.insert(query_val(1, l, r));
        int left = query_min(1, l, r), right = query_max(1, l, r), mid_val;
        if (left == right) return;
        mid_val = (left + right) / 2;
        int mid = upper_bound(arr.begin() + 1, arr.end(), mid_val) - arr.begin() - 1;
        if (mid >= l && mid < r) get_num(l, mid), get_num(mid + 1, r);
        return;
    }
};


void solve() { 
    int n, q; cin >> n >> q;
    arr.clear();
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr.begin() + 1, arr.end());
    SegmentTree tr(n);
    tr.buildtree(1, 1, n);
    tr.get_num(1, n);
    while (q--) {
        int t; cin >> t;
        if (tr.s.count(t)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
