#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 5], ans[MAXN + 5];

int cnt[MAXN + 5];
bool vis[MAXN + 5];
vector<int> vec;

void gao(int i) {
    if (vis[A[i]]) {
        if (i == vec.back()) swap(vec[vec.size() - 1], vec[vec.size() - 2]);
        ans[i] = vec.back(); vec.pop_back();
    } else {
        ans[i] = A[i];
        vis[A[i]] = true;
    }
}

void solve() {
    scanf("%d", &n);
    memset(cnt, 0, sizeof(int) * (n + 3));
    memset(vis, 0, sizeof(bool) * (n + 3));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        cnt[A[i]]++;
    }

    vec.clear();
    for (int i = 1; i <= n; i++) if (cnt[i] == 0) vec.push_back(i);
    printf("%d\n", n - (int) vec.size());
    for (int i = 1; i <= n; i++) if (cnt[i] == 0) gao(i);
    for (int i = 1; i <= n; i++) if (cnt[i] > 0) gao(i);
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
