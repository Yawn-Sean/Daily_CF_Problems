#include <bits/stdc++.h>
using namespace std;

set<int> query(int l, int r) {
    cout << "Q " << l << ' ' << r << endl;
    set<int> st;
    for (int i = l; i <= r; i++) {
        int x; cin >> x;
        st.insert(x);
    }
    return st;
}

void answer(const vector<int> &ans) {
    cout << 'A';
    for (int x: ans) cout << ' ' << x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if (!(cin >> n)) return 0;

    vector<int> ans(n, 0);

    // 当前还未被填入的位置取值全集
    set<int> remain;
    for (int i = 1; i <= n; ++i) remain.insert(i);

    auto erase_one = [&](set<int> &bag, int v) {
        auto it = bag.find(v);
        if (it != bag.end()) bag.erase(it);
    };

    // 在old_set中找一个不属于mid的元素：返回并从old_set移除
    auto take_missing = [&](set<int> &old_set, const set<int> &mid) -> int {
        for (int v : old_set) {
            if (!mid.count(v)) { erase_one(old_set, v); return v; }
        }
        return -1; // 理论不触发
    };

    int m = n; // 工作用 n 的副本（可能在奇数时会减 1）

    // 若为奇数，单独询问最后一位
    if (m & 1) {
        auto solo = query(m, m);
        ans[m - 1] = *solo.begin();
        erase_one(remain, ans[m - 1]);
        --m;
    }

    if (m > 1) {
        // 先得到左半段候选集合
        set<int> left = query(1, m / 2);

        // 右半段候选 = remain \ left
        set<int> right;
        for (int v : remain) if (!left.count(v)) right.insert(v);

        // 双指针式向内收缩
        for (int i = 2; i <= m / 2; ++i) {
            auto mid = query(i, m + 1 - i);
            // 左侧：在 left 里找一个不在 mid 的，就是第 i-1 个位置
            int lv = take_missing(left, mid);
            ans[i - 2] = lv;

            // 右侧：在 right 里找一个不在 mid 的，就是第 m - i + 2 个位置
            int rv = take_missing(right, mid);
            ans[m - i + 1] = rv;
        }

        // 剩下的两个位置
        ans[m / 2 - 1] = *left.begin();
        ans[m / 2]     = *right.begin();
    }

    answer(ans);
    return 0;
}
