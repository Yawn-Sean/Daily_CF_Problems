#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
pair<int, int> pii;  // first->beauty second->cost
vector<pair<int, int> > c, d;

/******************线段树模板**********************/
int SegTree[maxn << 2];

void BuildTree(int l, int r, int rt) {  // 建树，lr是总区间,rt是根结点一般为1
    if (l == r) {
        SegTree[rt] = 0;  // 初始化叶节点
        return;
    }
    int m = (l + r) >> 1;
    BuildTree(l, m, rt << 1);
    BuildTree(m + 1, r, rt << 1 | 1);
    SegTree[rt] = SegTree[rt << 1] + SegTree[rt << 1 | 1];
}

int Query(int L, int R, int l, int r, int rt) {  // 区间查询,LR是查询区间,lr是总区间,rt是根结点一般为1
    if (l >= L && r <= R)
        return SegTree[rt];
    int m = (l + r) >> 1;
    int ans1 = 0, ans2 = 0;
    if (L <= m)
        ans1 = Query(L, R, l, m, rt << 1);
    if (R > m)
        ans2 = Query(L, R, m + 1, r, rt << 1 | 1);
    return max(ans1, ans2);
}

void Update(int point, int value, int l, int r, int rt) {  // 单点更新，把point点的值改为value,lr是总区间,rt是根结点一般为1
    if (l == r) {
        SegTree[rt] = max(value, SegTree[rt]);
        return;
    }
    int m = (l + r) >> 1;
    if (point <= m)
        Update(point, value, l, m, rt << 1);
    else
        Update(point, value, m + 1, r, rt << 1 | 1);
    SegTree[rt] = max(SegTree[rt << 1], SegTree[rt << 1 | 1]);
}

/******************线段树模板**********************/
int main() {
    char ch;
    int n, C, D, t1, t2, max_cost = 0, ans = 0;
    cin >> n >> C >> D;
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2 >> ch;
        pii = make_pair(t1, t2);
        ch == 'C' ? c.push_back(pii) : d.push_back(pii);
        max_cost = max(t2, max_cost);
    }
    max_cost = max(max_cost, max(C, D));

    t1 = t2 = 0;  // C买一件D买一件
    for (auto &p: c)
        if (C >= p.second)
            t1 = max(t1, p.first);
    for (auto &p: d)
        if (D >= p.second)
            t2 = max(t2, p.first);
    if ((t1 & t2) != 0)  // t1和t2均不为0
        ans = t1 + t2;

    BuildTree(0, max_cost, 1);  // 买C两件
    for (auto x: c) {
        t1 = 0;
        if (C > x.second)
            t1 = Query(1, C - x.second, 0, max_cost, 1);
        Update(x.second, x.first, 0, max_cost, 1);
        if (t1 != 0)
            ans = max(ans, x.first + t1);
    }
    BuildTree(0, max_cost, 1);  // 买D两件
    for (auto x: d) {
        t1 = 0;
        if (D > x.second)
            t1 = Query(1, D - x.second, 0, max_cost, 1);
        Update(x.second, x.first, 0, max_cost, 1);
        if (t1 != 0)
            ans = max(ans, x.first + t1);
    }
    cout << ans << endl;
    return 0;
}