#include <bits/stdc++.h>
#define MAXN 5000
#define MAXM 100
using namespace std;

int n, m, A[MAXN + 5], ans[MAXN + 5];
int cnt[MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        cnt[A[i]]++;
    }

    vector<int> ord;
    for (int i = 1; i <= n; i++) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
        int cx = cnt[A[x]], cy = cnt[A[y]];
        if (cx != cy) return cx > cy;
        else return A[x] < A[y];
    });

    if (A[ord[0]] == A[ord.back()]) {
        for (int i = 1; i <= n; i++) ans[i] = A[i];
    } else {
        for (int i = 0; i < n; i++) if (A[ord[i]] != A[ord[0]]) {
            for (int j = 0; j < n; j++) ans[ord[(i + j) % n]] = A[ord[j]];
            break;
        }
    }

    int diff = 0;
    for (int i = 1; i <= n; i++) if (A[i] != ans[i]) diff++;
    printf("%d\n", diff);
    for (int i = 1; i <= n; i++) printf("%d %d\n", A[i], ans[i]);
    return 0;
}
