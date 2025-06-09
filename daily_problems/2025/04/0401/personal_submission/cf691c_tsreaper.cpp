#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n;
char s[MAXN + 5];

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    
    int L, P, R;
    for (L = 1; s[L] == '0'; L++);
    for (P = L; s[P] != '.' && P <= n; P++);
    for (R = n; s[R] == '0' || s[R] == '.'; R--);

    if (L + 1 == P) {
        for (int i = L; i <= R; i++) printf("%c", s[i]);
    } else if (L + 1 < P) {
        printf("%c", s[L]);
        if (L + 1 <= R) printf(".");
        for (int i = L + 1; i <= R; i++) if (s[i] != '.') printf("%c", s[i]);
        printf("E%d", P - (L + 1));
    } else {
        int cnt = 1;
        for (int i = P + 1; i <= R; i++) {
            if (s[i] != '0') {
                printf("%c", s[i]);
                if (i + 1 <= R) printf(".");
                for (int j = i + 1; j <= R; j++) printf("%c", s[j]);
                break;
            }
            cnt++;
        }
        printf("E%d", -cnt);
    }
    printf("\n");
    return 0;
}
