#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
#define INF ((int) 1e9)
using namespace std;

int n, ans, A[MAXN + 10];

vector<int> vec[MAXN + 10];
int f[MAXN + 10], tree[2][MAXN + 10];

int lb(int x) { return x & (-x); }

void update(int *tree, int pos, int val) {
    for (; pos <= n; pos += lb(pos)) tree[pos] = max(tree[pos], val);
}

int query(int *tree, int pos) {
    int ret = -INF;
    for (; pos; pos -= lb(pos)) ret = max(ret, tree[pos]);
    return ret;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 1; i <= n; i++) vec[i].clear();
    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && A[stk.top()] <= A[i]) vec[i].push_back(stk.top()), stk.pop();
        stk.push(i);
    }

    for (int t = 0; t <= 1; t++) for (int i = 1; i <= n; i++) tree[t][i] = -INF;
    f[1] = 1; update(tree[0], A[1], 1);
    for (int i = 2; i <= n; i++) {
        f[i] = max({
            2,
            query(tree[0], A[i]) + 1,
            query(tree[1], A[i]) + 2
        });
        update(tree[0], A[i], f[i]);
        for (int x : vec[i]) update(tree[1], A[x], f[x]);
    }

    ans = 0;
    for (int i = n, mx = -INF; i > 0; i--) {
        int t = f[i];
        if (mx >= A[i]) t++;
        ans = max(ans, t);
        mx = max(mx, A[i]);
    }
    printf("%d\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
