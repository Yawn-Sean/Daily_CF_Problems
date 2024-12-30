#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define INF ((int) 1e9)
using namespace std;

int n, K, A[MAXN + 10];

int gao(int L, int R) {
    int k = K;
    vector<int> vec;
    for (int i = L, j = L - 1; i <= R; i++) if (A[i] < 0) {
        int det = i - j - 1;
        if (det > 0) vec.push_back(det);
        j = i;
        k--;
    }
    if (k < 0) return INF;

    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        k -= vec[i];
        if (k < 0) return (vec.size() - i) * 2 + 1;
    }
    return 1;
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    int L = 1;
    while (L <= n && A[L] >= 0) L++;
    if (L > n) { printf("0\n"); return 0; }

    int ans;
    if (A[n] < 0) ans = gao(L, n);
    else {
        int R = n;
        while (R > 0 && A[R] >= 0) R--;
        ans = gao(L, R) + 1;
        K -= n - R;
        ans = min(ans, gao(L, R));
    }
    printf("%d\n", ans <= n ? ans : -1);
    return 0;
}
