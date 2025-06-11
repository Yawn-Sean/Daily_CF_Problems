#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
#define MAXQ ((int) 5e5)
using namespace std;

int n, q, ans[MAXQ + 10];

int tree[MAXN + 10];

int lb(int x) { return x & (-x); }

void add(int pos, int val) {
    for (; pos <= n; pos += lb(pos)) tree[pos] = min(tree[pos], val);
}

int query(int pos) {
    int ret = n + 1;
    for (; pos; pos -= lb(pos)) ret = min(ret, tree[pos]);
    return ret;
}

int main() {
    scanf("%d%d", &n, &q);
    vector<array<int, 3>> vec;
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (mp.count(x)) vec.push_back({mp[x], 1, i});
        mp[x] = i;
    }
    for (int i = 1; i <= q; i++) {
        int l, r; scanf("%d%d", &l, &r);
        vec.push_back({l, -i, r});
    }

    sort(vec.begin(), vec.end(), greater<array<int, 3>>());
    for (int i = 1; i <= n; i++) tree[i] = n + 1;
    for (auto &arr : vec) {
        if (arr[1] > 0) add(arr[2], arr[2] - arr[0]);
        else ans[-arr[1]] = query(arr[2]);
    }
    for (int i = 1; i <= q; i++) printf("%d\n", ans[i] <= n ? ans[i] : -1);
    return 0;
}
