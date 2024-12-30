#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXP 20
using namespace std;
 
int n, ans;
char s[MAXN + 10];
 
int last[MAXN + 10];
 
void solve() {
    scanf("%s", s + 1); n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        last[i] = last[i - 1];
        if (s[i] == '1') last[i] = i;
    }
 
    ans = 0;
    for (int i = 1; i <= n; i++) {
        int now = 0;
        int j;
        for (j = i; j > 0 && i - j + 1 <= MAXP; j--) {
            now += (s[j] - '0') << (i - j);
            if (now == i - j + 1) ans++;
        }
        int t = last[j];
        if (now >= i - j + 1 && now <= i - t) ans++;
    }
    printf("%d\n", ans);
}
 
int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
