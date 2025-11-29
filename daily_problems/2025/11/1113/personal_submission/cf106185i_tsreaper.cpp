#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n;
vector<int> pos[MAXN + 5];
long long ans;

int tree[MAXN * 2 + 5];

int lb(int x) { return x & (-x); }

void add(int pos, int val) {
    for (; pos <= n * 2; pos += lb(pos)) tree[pos] += val;
}

int query(int pos) {
    int ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

bool solve() {
    scanf("%d", &n);
    if (n == 0) return false;
    for (int i = 1; i <= n; i++) pos[i].clear();
    for (int i = 1; i <= n * 2; i++) {
        int x; scanf("%d", &x);
        pos[x].push_back(i);
    }

    vector<pii> vec;
    for (int i = 1; i <= n; i++) {
        int sz = pos[i].size();
        for (int j = 0; j < sz / 2; j++) vec.push_back({pos[i][j], pos[i][j + sz / 2]});
    }
    sort(vec.begin(), vec.end());

    ans = 1LL * n * (n - 1) / 2;
    memset(tree, 0, sizeof(int) * (n * 2 + 3));
    for (pii p : vec) {
        ans -= query(p.second) - query(p.first);
        add(p.second, 1);
    }
    printf("%lld\n", ans);
    return true;
}

int main() {
    while (solve());
    return 0;
}
