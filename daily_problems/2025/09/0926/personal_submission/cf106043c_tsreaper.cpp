#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 5], ans[MAXN + 5];

vector<int> pos[MAXN + 5];
int root[MAXN + 5], len[MAXN + 5];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

void merge(int x, int y) {
    x = findroot(x); y = findroot(y);
    if (x == y) return;
    root[x] = y; len[y] += len[x];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        if (A[i] < n) pos[A[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) root[i] = i, len[i] = 1;
    for (int k = 0, now = n; k < n; k++) {
        int mx = 0;
        for (int idx : pos[k]) {
            if (idx > 1 && A[idx - 1] <= k) merge(idx - 1, idx);
            if (idx < n && A[idx + 1] <= k) merge(idx + 1, idx);
            mx = max(mx, len[findroot(idx)]);
        }
        now = min(now, mx);
        ans[now] = k + 1;
    }
    for (int i = n - 1; i > 0; i--) ans[i] = max(ans[i], ans[i + 1]);
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
