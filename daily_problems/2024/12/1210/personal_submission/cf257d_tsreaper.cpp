#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 5], ans[MAXN + 5];

int main() {
    scanf("%d", &n);
    long long sm = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        ans[i] = 1;
        sm += A[i];
    }
    for (int i = n; i > 0 && !(-A[1] <= sm && sm <= A[1]); i--)
        if (sm - A[i] * 2 >= -A[1]) ans[i] = -1, sm -= A[i] * 2;
    assert(-A[1] <= sm && sm <= A[1]);
    if (sm < 0) for (int i = 1; i <= n; i++) ans[i] = -ans[i];
    for (int i = 1; i <= n; i++) printf("%c", ans[i] > 0 ? '+' : '-');
    printf("\n");
    return 0;
}
