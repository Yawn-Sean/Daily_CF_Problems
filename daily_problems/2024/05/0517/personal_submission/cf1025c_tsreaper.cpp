#include <bits/stdc++.h>
#define MAXS ((int) 1e5)
using namespace std;

int n, ans;
char s[MAXS * 2 + 10];

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) s[n + i] = s[i];

    ans = 1;
    for (int i = 1, j = 1; i <= n * 2; i++) if (i == n * 2 || s[i] == s[i + 1]) {
        ans = max(ans, min(n, i - j + 1));
        j = i + 1;
    }
    printf("%d\n", ans);
    return 0;
}
