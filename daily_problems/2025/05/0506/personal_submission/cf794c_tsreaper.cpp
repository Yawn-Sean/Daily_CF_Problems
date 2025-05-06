#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n;
char s1[MAXN + 5], s2[MAXN + 5], ans[MAXN + 5];

int main() {
    scanf("%s%s", s1 + 1, s2 + 1);
    n = strlen(s1 + 1);
    sort(s1 + 1, s1 + n + 1);
    sort(s2 + 1, s2 + n + 1, greater<char>());
    
    for (int i = 1, l = 1, r = n, l1 = 1, r1 = (n + 1) / 2, l2 = 1, r2 = n / 2; i <= n; i++) {
        if (i & 1) {
            if (s1[l1] < s2[l2]) ans[l++] = s1[l1++];
            else ans[r--] = s1[r1--];
        } else {
            if (s1[l1] < s2[l2]) ans[l++] = s2[l2++];
            else ans[r--] = s2[r2--];
        }
    }

    printf("%s\n", ans + 1);
    return 0;
}
