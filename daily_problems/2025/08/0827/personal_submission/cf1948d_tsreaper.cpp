#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n;
char s[MAXN + 5];

bool match(char x, char y) {
    if (x == '?' || y == '?') return true;
    return x == y;
}

bool check(int K) {
    int now = 0;
    for (int i = K + 1; i <= K * 2; i++) now += match(s[i - K], s[i]);
    if (now == K) return true;
    for (int i = K * 2 + 1; i <= n; i++) {
        now -= match(s[i - K * 2], s[i - K]);
        now += match(s[i - K], s[i]);
        if (now == K) return true;
    }
    return false;
}

void solve() {
    scanf("%s", s + 1); n = strlen(s + 1);
    for (int k = n / 2; k > 0; k--) if (check(k)) { printf("%d\n", k * 2); return; }
    printf("0\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
