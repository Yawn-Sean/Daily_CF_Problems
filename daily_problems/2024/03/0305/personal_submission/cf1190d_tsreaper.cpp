#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, X[MAXN + 10], Y[MAXN + 10];
long long ans;

int tree[MAXN + 10];
bool vis[MAXN + 10];

int lb(int x) { return x & (-x); }

void add(int pos) {
    for (; pos <= m; pos += lb(pos)) tree[pos]++;
}

int query(int pos) {
    int ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &X[i], &Y[i]);

    map<int, int> mp;
    for (int i = 1; i <= n; i++) mp[X[i]] = 1;
    for (auto &p : mp) p.second = ++m;
    for (int i = 1; i <= n; i++) X[i] = mp[X[i]];
    m++;

    map<int, vector<int>> points;
    for (int i = 1; i <= n; i++) points[-Y[i]].push_back(X[i]);

    for (auto &p : points) {
        auto &vec = p.second;
        for (int x : vec) if (!vis[x]) { vis[x] = true; add(x); }
        int t = query(m);
        ans += 1LL * (1 + t) * t / 2;

        vec.push_back(0); vec.push_back(m);
        sort(vec.begin(), vec.end());
        for (int i = 1; i < vec.size(); i++) {
            int t = query(vec[i] - 1) - query(vec[i - 1]);
            ans -= 1LL * (1 + t) * t / 2;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
