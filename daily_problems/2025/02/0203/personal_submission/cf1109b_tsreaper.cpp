#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n;
char s[MAXN + 5];

int main() {
    scanf("%s", s); n = strlen(s);
    for (int i = 1; i < n; i++) {
        bool ok = true;
        for (int l = 0, r = n - 1; l < r; l++, r--) if (s[(l + i) % n] != s[(r + i) % n]) { ok = false; break; }
        if (ok) {
            for (int l = 0; l < n; l++) if (s[l] != s[(l + i) % n]) { printf("1\n"); return 0; }
        }
    }
    for (int i = 0; i + 1 < n / 2; i++) if (s[i] != s[i + 1]) { printf("2\n"); return 0; }
    printf("Impossible\n");
    return 0;
}
