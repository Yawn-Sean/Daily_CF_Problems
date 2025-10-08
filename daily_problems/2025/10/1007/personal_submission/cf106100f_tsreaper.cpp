#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n, A[MAXN + 5], B[MAXN + 5];
long long ans;

unordered_map<int, vector<int>> pos;
int tree[MAXN + 5];

int lb(int x) { return x & (-x); }

void add(int pos, int val) {
    for (; pos <= n; pos += lb(pos)) tree[pos] += val;
}

int query(int pos) {
    int ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]); A[i] -= i;
        pos[A[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]), B[i] -= i;

    for (auto &entry : pos) reverse(entry.second.begin(), entry.second.end());
    for (int i = 1; i <= n; i++) {
        auto &tmp = pos[B[i]];
        if (tmp.empty()) { printf("-1\n"); return 0; }
        int x = tmp.back(); tmp.pop_back();
        ans += x - query(x) - 1;
        add(x, 1);
    }
    printf("%lld\n", ans);
    return 0;
}
