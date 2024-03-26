#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, ans[MAXN + 10], last[MAXN + 10];

int main() {
    scanf("%d", &n);
    stack<int> stk;
    for (int i = 1, j = 0; i <= n * 2; i++) {
        char s[3]; scanf("%s", s);
        if (s[0] == '+') {
            j++;
            if (!stk.empty()) last[j] = stk.top();
            stk.push(j);
        } else {
            int x; scanf("%d", &x);
            if (stk.empty()) { printf("NO\n"); return 0; }
            ans[stk.top()] = x;
            stk.pop();
        }
    }
    for (int i = 1; i <= n; i++) if (last[i] && ans[last[i]] < ans[i]) { printf("NO\n"); return 0; }
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
