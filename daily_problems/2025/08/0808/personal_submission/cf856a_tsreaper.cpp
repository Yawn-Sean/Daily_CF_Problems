#include <bits/stdc++.h>
#define MAXN 100
#define MAXA ((int) 1e6)
using namespace std;

int n, A[MAXN + 5], B[MAXN + 5];
bool vis[MAXA + 5];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);

    vector<int> det;
    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) det.push_back(A[j] - A[i]);
    sort(det.begin(), det.end());
    det.resize(unique(det.begin(), det.end()) - det.begin());

    printf("YES\n");
    for (int i = 1, now = 1; i <= n; i++) {
        while (vis[now]) now++;
        printf("%d%c", now, "\n "[i < n]);
        for (int x : det) if (now + x <= MAXA) vis[now + x] = true;
        B[i] = now;
        now++;
    }
    for (int i = 1; i <= n; i++) for (int x : det) if (B[i] + x <= MAXA) vis[B[i] + x] = false;
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
