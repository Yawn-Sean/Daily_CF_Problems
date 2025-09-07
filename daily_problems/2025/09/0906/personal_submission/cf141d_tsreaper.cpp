#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define INF ((long long) 1e18)
using namespace std;
typedef pair<long long, int> pli;

int n, m, K;
vector<array<int, 4>> vec;

int from[MAXN + 5];
pli tree[2][MAXN * 2 + 5];

int lb(int x) { return x & (-x); }

void update(pli *tree, int pos, pli val) {
    for (; pos <= m; pos += lb(pos)) tree[pos] = min(tree[pos], val);
}

pli query(pli *tree, int pos) {
    pli ret = pli(INF, -1);
    for (; pos; pos -= lb(pos)) ret = min(ret, tree[pos]);
    return ret;
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
        if (a - d >= 0) vec.push_back({a + b, a - d, c + d, i});
    }
    vec.push_back({K, K, 0, 0});
    sort(vec.begin(), vec.end());

    map<int, int> mp;
    mp[0] = 1;
    for (auto &arr : vec) mp[arr[0]] = mp[arr[1]] = 1;
    for (auto &p : mp) p.second = ++m;

    pli ans = pli(INF, -1);
    for (int i = 1; i <= m; i++) tree[0][i] = tree[1][i] = {INF, -1};
    update(tree[0], 1, pli(0, -1)); update(tree[1], m, pli(0, -1));
    for (auto &arr : vec) {
        int t = mp[arr[1]];
        pli p0 = query(tree[0], t);
        p0.first += (long long) arr[1] + arr[2];
        pli p1 = query(tree[1], m + 1 - t);
        p1.first += (long long) arr[2] - arr[1];
        pli p = min(p0, p1);
        from[arr[3]] = p.second;
        if (arr[0] >= K) ans = min(ans, pli(p.first, arr[3]));

        t = mp[arr[0]];
        update(tree[0], t, pli(p.first - arr[0], arr[3]));
        update(tree[1], m + 1 - t, pli(p.first + arr[0], arr[3]));
    }

    vector<int> plan;
    while (ans.second >= 0) {
        if (ans.second > 0) plan.push_back(ans.second);
        ans.second = from[ans.second];
    }
    reverse(plan.begin(), plan.end());

    printf("%lld\n%d\n", ans.first, plan.size());
    for (int i = 0; i < plan.size(); i++) printf("%d%c", plan[i], "\n "[i + 1 < plan.size()]);
    return 0;
}
