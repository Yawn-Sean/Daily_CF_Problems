#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, ans;
char s[MAXN + 10];

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    for (int i = 1, j = 0; i <= n; i++) if (s[i] == 'F') {
        j++;
        if (i == j) continue;
        ans = max(ans + 1, i - j);
    }
    printf("%d\n", ans);
    return 0;
}
