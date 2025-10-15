#include <bits/stdc++.h>
#define MAXN 3000
using namespace std;

int n, ans[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1, j = 1; i <= n; i++) {
        while (j < n) {
            printf("? %d %d\n", i, j); fflush(stdout);
            char s[3]; scanf("%s", s);
            if (s[0] == '=') break;
            j++;
        }
        ans[i] = j;
    }
    printf("!");
    for (int i = 1; i <= n; i++) printf(" %d", ans[i]);
    printf("\n"); fflush(stdout);
    return 0;
}
