#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
 
int n, A[MAXN + 10], B[MAXN + 10];
long long ans;
 
int vis[MAXN + 10];
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
    for (int i = 1, cnt = 0; i <= n; i++) if (!vis[i]) {
        cnt++;
        stack<int> stk;
        for (int j = i; ; j = B[j]) {
            if (vis[j] == cnt) {
                int mn = A[j];
                while (stk.top() != j) {
                    mn = min(mn, A[stk.top()]);
                    stk.pop();
                }
                ans += mn;
            }
            if (vis[j]) break;
            vis[j] = cnt;
            stk.push(j);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
