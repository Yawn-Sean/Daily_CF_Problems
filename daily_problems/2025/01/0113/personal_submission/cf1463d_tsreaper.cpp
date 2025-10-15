#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n;

bool vis[MAXN * 2 + 5];
vector<int> A, B;

bool check1(int lim) {
    if (lim == 0) return true;
    for (int i = 1; i <= lim; i++) if (A[i - 1] >= B[n - 1 - lim + i]) return false;
    return true;
}

bool check2(int lim) {
    if (lim == 0) return true;
    for (int i = 1; i <= lim; i++) if (A[n - i] <= B[lim - i]) return false;
    return true;
}

void solve() {
    scanf("%d", &n);
    memset(vis, 0, sizeof(bool) * (n * 2 + 3));
    A.clear();
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        vis[x] = true; A.push_back(x);
    }
    B.clear();
    for (int i = 1; i <= n * 2; i++) if (!vis[i]) B.push_back(i);

    int head = 0, tail = n;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (check1(mid)) head = mid;
        else tail = mid - 1;
    }
    int R = head;

    head = 0; tail = n;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (check2(mid)) head = mid;
        else tail = mid - 1;
    }
    int L = n - head;

    printf("%d\n", max(0, R - L + 1));
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
