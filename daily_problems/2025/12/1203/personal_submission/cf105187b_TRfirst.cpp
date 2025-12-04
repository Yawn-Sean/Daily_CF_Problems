#include <bits/stdc++.h>
using namespace std;
#define endl '\n'



struct node {
    int l, r, v1, v2;
};

void solve(){
    int n;
    cin >> n;
    vector<int> nums(2 * n + 5);
    for (int i = 1; i <= 2 * n; i++) cin >> nums[i];

    vector<node> tree(4 * (5e5 + 5) + 5);

    auto pushup = [&](int x) -> void {
        tree[x].v1 = tree[2 * x].v1 + tree[2 * x + 1].v1;
        tree[x].v2 = tree[2 * x].v2 + tree[2 * x + 1].v2;
    };

    auto build = [&](auto build, int x, int l, int r) -> void {
        tree[x].l = l, tree[x].r = r;
        if (tree[x].l == tree[x].r) return;
        int mid = (l + r) >> 1;
        build(build, 2 * x, l, mid);
        build(build, 2 * x + 1, mid + 1, r);
    };

    auto change = [&](auto change, int x, int th, int v, int op) -> void {
        int mid = (tree[x].l + tree[x].r) >> 1;
        if (op == 1) if (tree[x].l == tree[x].r) {tree[x].v1 += v; return;}
        if (op == 2) if (tree[x].l == tree[x].r) {tree[x].v2 += v; return;}
        if (th <= mid) change(change, 2 * x, th, v, op);
        else change(change, 2 * x + 1, th, v, op);
        pushup(x);
    };

    auto query = [&](auto query, int x, int l, int r, int op) -> int {
        int res = 0;
        if (op == 1) if (l <= tree[x].l && tree[x].r <= r) return tree[x].v1;
        if (op == 2) if (l <= tree[x].l && tree[x].r <= r) return tree[x].v2;
        int mid = (tree[x].l + tree[x].r) >> 1;
        if (l <= mid) res += query(query, 2 * x, l, r, op);
        if (mid < r) res += query(query, 2 * x + 1, l, r, op);
        return res;
    };

    build(build, 1, 1, 5e5 + 5);

    vector<int> v_1(2 * n + 5), v_2(2 * n + 5);
    vector<int> to(2 * n + 5);

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        a++, b++;
        to[a] = b, to[b] = a;
        int v1 = min({max(nums[a] + 3, nums[b]), max(nums[a], nums[b] + 3), max(nums[a] + 1, nums[b] + 1)});
        int v2 = min(nums[a], nums[b]);
        v_1[a] = v1, v_2[a] = v2;
        v_1[b] = v1, v_2[b] = v2;
        change(change, 1, v1, 1, 1);
        change(change, 1, v2, 1, 2);
    }

    for (int i = 1; i <= 2 * n; i++) {
        change(change, 1, v_1[i], -1, 1);
        change(change, 1, v_2[i], -1, 2);
        int q1 = query(query, 1, 1, nums[i] + 3, 1);
        int q2 = query(query, 1, 1, nums[i] + 3, 2);
        cout << 1 + ((q2 - q1) + 2 * (n - 1 - q2)) + (nums[i] + 3 < nums[to[i]]) << " ";
        change(change, 1, v_1[i], 1, 1);
        change(change, 1, v_2[i], 1, 2);
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _T = 1;
    // cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}