#include <bits/stdc++.h>
 
using namespace std;

struct fenwick_tree {
    vector<int> bit;  // binary indexed tree
    int n;
    fenwick_tree(int n_) : n(n_ + 1), bit(n_ + 1, 0) {}
    void add(int idx, int delta = 1) {
        for (++idx; idx < n; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }
    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            ret += bit[idx];
        }
        return ret;
    }
};

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> b(n);
    for (auto& x : b) {
        scanf("%d", &x);
    }
    fenwick_tree t(n);
    vector<int> a(n);
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && b[j] + t.sum(min(j + k - 1, n - 1)) == i) {
                a[i] = j;
                t.add(j);
                vis[j] = true;
                break;
            }
        }
    }
    for (auto& x : a) {
        printf("%d ", x + 1);
    }
    return 0;
}

