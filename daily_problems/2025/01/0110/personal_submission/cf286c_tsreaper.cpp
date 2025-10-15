#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, A[MAXN + 5], ans[MAXN + 5];
bool flag[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    int m; scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int x; scanf("%d", &x);
        flag[x] = true;
    }
    stack<int> stk;
    for (int i = n; i > 0; i--) {
        if (flag[i]) {
            ans[i] = -1;
            stk.push(A[i]);
        } else {
            if (!stk.empty() && stk.top() == A[i]) {
                ans[i] = 1;
                stk.pop();
            } else {
                ans[i] = -1;
                stk.push(A[i]);
            }
        }
    }
    if (stk.empty()) {
        printf("YES\n");
        for (int i = 1; i <= n; i++) printf("%d%c", ans[i] * A[i], "\n "[i < n]);
    } else {
        printf("NO\n");
    }
    return 0;
}
