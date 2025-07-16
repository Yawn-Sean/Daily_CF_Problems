#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n;
char s[MAXN + 5];

array<int, 2> f[MAXN + 5];
int g[MAXN + 5];

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);

    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        f[i] = {-1, -1};
        if (s[i] == '(' || s[i] == '[') stk.push(i);
        else if (!stk.empty()) {
            int t = stk.top(); stk.pop();
            g[i] = t;
        }
    }

    for (int i = 1; i <= n; i++) if (g[i] > 0) {
        bool bad = true;
        if (s[g[i]] == '(' && s[i] == ')') bad = false;
        if (s[g[i]] == '[' && s[i] == ']') bad = false;
        if (bad) continue;

        int val = (s[i] == ']' ? 1 : 0);
        if (g[i] + 1 == i) f[i] = {val, g[i]};
        else {
            if (f[i - 1][0] < 0 || f[i - 1][1] != g[i] + 1) continue;
            f[i] = {f[i - 1][0] + val, g[i]};
        }
        if (g[i] - 1 > 0 && f[g[i] - 1][0] >= 0) f[i][0] += f[g[i] - 1][0], f[i][1] = f[g[i] - 1][1];
    }

    int best = 0, fin = 0;
    for (int i = 1; i <= n; i++) if (f[i][0] > best) best = f[i][0], fin = i;
    if (best == 0) printf("0\n");
    else {
        printf("%d\n", best);
        for (int i = f[fin][1]; i <= fin; i++) printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}
