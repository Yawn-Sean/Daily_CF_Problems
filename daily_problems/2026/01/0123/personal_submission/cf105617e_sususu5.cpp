#include <algorithm>
#include <bit>
#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <stack>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <numbers>
#include <cmath>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int MOD = 1e9 + 7;

ll query(int l, int r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    ll x; cin >> x;
    if (x == -1) exit(0);
    return x;
}

void report(ll m) {
    cout << "! " << m << '\n';
    cout.flush();
}

class SegmentTree {
public:
    SegmentTree(vector<int>& a, int flag) : n(a.size()), tree(2 << (bit_width(n - 1))), flag(flag) {
        build(a, 1, 0, a.size() - 1);
    }

    void update(int i, int val) {
        update(1, i, val, 0, n - 1);
    }

    int query(int ql, int qr) {
        return query(1, ql, qr, 0, n - 1);
    }

    int find_kth(int k) {
        return find_kth(1, k, 0, n - 1);
    }

private:
    unsigned int n;
    vector<int> tree;
    int flag;

    int merge_val(int x, int y) {
        if (flag == 1) return x + y;
        if (flag == 2) return max(x, y);
    }

    void maintain(int node) {
        tree[node] = merge_val(tree[node * 2], tree[node * 2 + 1]);
    }

    void build(vector<int>& a, int node, int l, int r) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, node * 2, l, mid);
        build(a, node * 2 + 1, mid + 1, r);
        maintain(node);
    }

    void update(int node, int i, int val, int l, int r) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (i <= mid) update(node * 2, i, val, l, mid);
        else update(node * 2 + 1, i, val, mid + 1, r);
        maintain(node);
    }

    int query(int node, int ql, int qr, int l, int r) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }
        int mid = (l + r) / 2;
        if (qr <= mid) return query(node * 2, ql, qr, l, mid);
        if (ql > mid) return query(node * 2 + 1, ql, qr, mid + 1, r);
        int l_res = query(node * 2, ql, qr, l, mid), r_res = query(node * 2 + 1, ql, qr, mid + 1, r);
        return merge_val(l_res, r_res);
    }

    int find_kth(int node, int k, int l, int r) {
        if (l == r) return l;
        int mid = (l + r) / 2;
        int left_sum = tree[node * 2];
        if (k <= left_sum) return find_kth(node * 2, k, l, mid);
        else return find_kth(node * 2 + 1, k - left_sum, mid + 1, r);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums) cin >> num;

    vector<int> arr1(n, 1);
    SegmentTree tree1(arr1, 1);
    vector<int> pos(n);
    for (int i = n - 1; i >= 0; i--) {
        pos[i] = tree1.find_kth(nums[i]);
        tree1.update(pos[i], 0);
    }

    vector<int> zeros(n);
    SegmentTree tree2(zeros, 2);
    int mx = 1;
    for (int i = 0; i < n; i++) {
        int pre = 0;
        if (pos[i] > 0) pre = tree2.query(0, pos[i] - 1);
        mx = max(mx, pre + 1);
        cout << mx << '\n';
        tree2.update(pos[i], pre + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}