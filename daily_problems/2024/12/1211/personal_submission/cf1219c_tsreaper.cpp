#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, L;
char s[MAXN + 5];

int main() {
    scanf("%d%s", &L, s + 1); n = strlen(s + 1);
    if (n % L) {
        for (int i = 1; i <= n; i += L) {
            printf("1");
            for (int j = 2; j <= L; j++) printf("0");
        }
    } else {
        bool flag = true;
        for (int i = 1; i <= L; i++) if (s[i] != '9') { flag = false; break; }
        if (flag) {
            for (int i = 1; i <= n + L; i += L) {
                printf("1");
                for (int j = 2; j <= L; j++) printf("0");
            }
        } else {
            bool flag = true;
            for (int i = L + 1; i <= n; i++) {
                int j = (i - 1) % L + 1;
                if (s[i] < s[j]) { flag = false; break; }
                if (s[i] > s[j]) break;
            }
            if (flag) {
                s[L]++;
                for (int i = L; i > 0; i--) {
                    if (s[i] <= '9') break;
                    s[i] = '0'; s[i - 1]++;
                }
            }
            for (int i = 1; i <= n; i += L) for (int j = 1; j <= L; j++) printf("%c", s[j]);
        }
    }
    printf("\n");
    return 0;
}
