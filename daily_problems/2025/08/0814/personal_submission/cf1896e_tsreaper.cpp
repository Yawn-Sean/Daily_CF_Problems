#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;
typedef pair<int, int> pii;

int n, ans[MAXN + 5];
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

void solve() {
    scanf("%d", &n);

    vector<pii> vec;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (i > x) vec.push_back({i, x + n});
        else vec.push_back({i, x}), vec.push_back({i + n, x + n});
    }
    sort(vec.begin(), vec.end(), greater<pii>());

    memset(tree, 0, sizeof(int) * (n * 2 + 3));
    for (pii p : vec) {
        if (p.first <= n) {
            int x = p.second - (p.second > n ? n : 0);
            ans[x] = p.second - p.first - query(p.second);
        }
        add(p.second, 1);
    }

    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
