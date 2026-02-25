#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct SegTree {
    int n;
    vector<ll> tree;

    SegTree(int size) {
        n = size;
        tree.resize(4 * n);
    }

    void build(vector<ll>& nums, int node, int l, int r) {
        if (l == r) {
            tree[node] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, ll val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(node * 2, l, mid, pos, val);
        else
            update(node * 2 + 1, mid + 1, r, pos, val);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query_first(int node, int l, int r, int ql, int qr, ll val) {
        if (r < ql || l > qr || tree[node] < val)
            return -1;

        if (l == r)
            return l;

        int mid = (l + r) / 2;
        int left = query_first(node * 2, l, mid, ql, qr, val);
        if (left != -1)
            return left;

        return query_first(node * 2 + 1, mid + 1, r, ql, qr, val);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    SegTree seg(n);
    seg.build(nums, 1, 0, n - 1);

    while (q--) {
        int l, r;
        ll val;
        cin >> l >> r >> val;
        l--; 
        r--;

        ll ans = 0;

        while (true) {
            int pos = seg.query_first(1, 0, n - 1, l, r, val);
            if (pos == -1) break;

            ans += nums[pos];
            seg.update(1, 0, n - 1, pos, -1);
            l = pos;  
        }

        cout << ans << "\n";
    }

    return 0;
}
