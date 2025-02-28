#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n;
char s[MAXN + 5];

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    if (n & 1) {
        for (int i = 1; i <= n / 2 + 1; i++) printf("4");
        for (int i = 1; i <= n / 2 + 1; i++) printf("7");
        printf("\n");
        return 0;
    }

    int i, a = 0, b = 0;
    for (i = 1; i <= n; i++) {
        if (s[i] == '4') a++;
        else if (s[i] == '7') b++;
        else break;
    }
    if (i > n) {
        if (a == b) {
            printf("%s\n", s + 1);
            return 0;
        }
        i--;
    }
    for (; i > 0; i--) {
        if (s[i] == '4') a--;
        else if (s[i] == '7') b--;
        for (int d = s[i] - '0' + 1; d <= 9; d++) if (d == 4 || d == 7) {
            if (d == 4) a++;
            else b++;
            if (a <= n / 2 && b <= n / 2) {
                for (int j = 1; j < i; j++) printf("%c", s[j]);
                printf("%d", d);
                for (int j = i + 1; j <= n; j++) {
                    if (a < n / 2) printf("4"), a++;
                    else printf("7"), b++;
                }
                printf("\n");
                return 0;
            }
            if (d == 4) a--;
            else b--;
        }
    }

    for (int i = 1; i <= n / 2 + 1; i++) printf("4");
    for (int i = 1; i <= n / 2 + 1; i++) printf("7");
    printf("\n");
    return 0;
}
