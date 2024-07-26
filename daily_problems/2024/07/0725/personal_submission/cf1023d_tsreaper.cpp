#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXQ ((int) 2e5)
using namespace std;

int n, q, A[MAXN + 10];

int L[MAXQ + 10], R[MAXQ + 10], B[MAXN + 10];
vector<int> evt[MAXN + 10];

int main() {
    scanf("%d%d", &n, &q);
    int zero = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        if (A[i] == 0) { zero = i; continue; }
        if (L[A[i]] == 0) L[A[i]] = i;
        R[A[i]] = i;
    }

    if (L[q] == 0) {
        if (zero == 0) { printf("NO\n"); return 0; }
        L[q] = R[q] = zero;
    }

    for (int i = 1; i <= q; i++) if (L[i]) {
        evt[L[i]].push_back(i);
        evt[R[i] + 1].push_back(-i);
    }
    set<int> st;
    for (int i = 1; i <= n; i++) {
        for (int x : evt[i]) {
            if (x > 0) st.insert(x);
            else st.erase(-x);
        }
        if (!st.empty()) B[i] = *prev(st.end());
        if (A[i] && B[i] && A[i] != B[i]) { printf("NO\n"); return 0; }
    }

    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d%c", B[i] ? B[i] : 1, "\n "[i < n]);
    return 0;
}
