#include <bits/stdc++.h>
#define MAXN 1500
using namespace std;

int n, q;
char s[MAXN + 10];

int main() {
    scanf("%d%s%d", &n, s + 1, &q);
    while (q--) {
        int x;
        char c[3]; scanf("%d%s", &x, c);
        int ans = 0;
        for (int i = 1, j = 1, cnt = 0; i <= n; i++) {
            if (s[i] != c[0]) cnt++;
            while (j <= i && cnt > x) {
                if (s[j] != c[0]) cnt--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
