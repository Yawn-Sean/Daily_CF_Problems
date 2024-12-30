#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
#define MAGIC 10
using namespace std;

int n;
char s[MAXN + 10];
long long ans;

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        int best = 0;
        for (int x = i - 1; x > 0 && x >= i - MAGIC; x--) for (int k = 1; x + k <= i && x - k >= i - MAGIC; k++)
            if (s[x] == s[x - k] && s[x] == s[x + k]) best = max(best, x - k);
        ans += best;
    }
    printf("%lld\n", ans);
    return 0;
}
