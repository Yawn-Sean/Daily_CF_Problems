#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, ans[MAXN + 10];

bool flag[MAXN + 10];

void query() {
    vector<int> vec;
    for (int i = 1; i <= n; i++) if (flag[i]) vec.push_back(i);
    printf("%d\n", vec.size());
    for (int i = 0; i < vec.size(); i++) printf("%d%c", vec[i], "\n "[i + 1 < vec.size()]);
    fflush(stdout);

    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (!flag[i]) ans[i] = min(ans[i], x);
    }
}

void gao(vector<int> L, vector<int> R) {
    if (L.empty()) return;

    memset(flag, 0, sizeof(bool) * (n + 3));
    for (int i = 0; i < L.size(); i++) {
        int mid = (L[i] + R[i]) >> 1;
        for (int j = L[i]; j <= mid; j++) flag[j] = true;
    }
    query();

    memset(flag, 0, sizeof(bool) * (n + 3));
    for (int i = 0; i < L.size(); i++) {
        int mid = (L[i] + R[i]) >> 1;
        for (int j = mid + 1; j <= R[i]; j++) flag[j] = true;
    }
    query();

    vector<int> LL, RR;
    for (int i = 0; i < L.size(); i++) {
        int mid = (L[i] + R[i]) >> 1;
        if (L[i] < mid) LL.push_back(L[i]), RR.push_back(mid);
        if (mid + 1 < R[i]) LL.push_back(mid + 1), RR.push_back(R[i]);
    }
    gao(LL, RR);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) ans[i] = 1e9 + 7;

    vector<int> L = {1}, R = {n};
    gao(L, R);

    printf("-1\n");
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    fflush(stdout);
    return 0;
}
