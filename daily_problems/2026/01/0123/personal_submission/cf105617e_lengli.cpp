#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct FenwickTree {
    int n;
    vector<int> tree;

    FenwickTree(int size) : n(size), tree(size + 1, 0) {}

    void add(int i, int delta) {
        for (++i; i <= n; i += i & -i) {
            tree[i] += delta;
        }
    }

    int find_kth(int k) {
        int idx = 0;
        int current_sum = 0;
        for (int i = 1 << (31 - __builtin_clz(n)); i > 0; i >>= 1) {
            if (idx + i <= n && current_sum + tree[idx + i] <= k) {
                idx += i;
                current_sum += tree[idx];
            }
        }
        return idx;
    }
};

struct MaxFenwickTree {
    int n;
    vector<int> tree;

    MaxFenwickTree(int size) : n(size), tree(size + 1, 0) {}

    void update(int i, int val) {
        for (++i; i <= n; i += i & -i) {
            tree[i] = max(tree[i], val);
        }
    }

    int query(int i) {
        int res = 0;
        for (++i; i > 0; i -= i & -i) {
            res = max(res, tree[i]);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    FenwickTree fen(n);
    for (int i = 0; i < n; ++i) {
        fen.add(i, 1);
    }

    vector<int> pos(n);
    for (int i = n - 1; i >= 0; --i) {
        pos[i] = fen.find_kth(nums[i]);
        fen.add(pos[i], -1);
    }

    MaxFenwickTree max_fen(n);
    int ans = 0;
    
    for (int i = 0; i < n; ++i) {
        int res = max_fen.query(pos[i] - 1) + 1;
        ans = max(ans, res);
        cout << ans << "\n";
        max_fen.update(pos[i], res);
    }

    return 0;
}
