#include <bits/stdc++.h>
#define MAXQ ((int) 1e5)
using namespace std;

int n, tree[MAXQ * 2 + 10];

int lb(int x) { return x & (-x); }

void add(int pos) {
    for (; pos <= n; pos += lb(pos)) tree[pos]++;
}

int query(int pos) {
    int ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

long long gao(vector<int> &vec) {
    map<int, int> mp;
    for (int x : vec) mp[x] = 1;
    for (auto &p : mp) p.second = ++n;

    long long ret = 0;
    for (int x : vec) {
        x = mp[x];
        ret += query(n) - query(x);
        add(x);
    }
    return ret;
}

int main() {
    int q; scanf("%d", &q);
    map<int, int> mp;
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        if (mp.count(x) == 0) mp[x] = x;
        if (mp.count(y) == 0) mp[y] = y;
        swap(mp[x], mp[y]);
    }

    vector<int> vec;
    for (auto &p : mp) vec.push_back(p.second);
    long long ans = gao(vec);

    vector<int> pos;
    for (auto &p : mp) pos.push_back(p.first);
    for (auto &p : mp) {
        int x = max(p.first, p.second), y = min(p.first, p.second);
        int cnt = upper_bound(pos.begin(), pos.end(), x) - upper_bound(pos.begin(), pos.end(), y);
        ans += x - y - cnt;
    }

    printf("%lld\n", ans);
    return 0;
}
