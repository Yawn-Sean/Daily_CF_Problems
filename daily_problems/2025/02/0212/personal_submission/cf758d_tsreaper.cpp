#include <bits/stdc++.h>
#define MAXN 60
using namespace std;
typedef pair<int, int> pii;

int B, n;
char s[MAXN + 5];
long long ans;

pii f[MAXN + 5];

int main() {
    scanf("%d%s", &B, s + 1); n = strlen(s + 1);
    
    f[n + 1] = {0, n + 1};
    for (int i = n; i > 0; i--) {
        long long now = s[i] - '0';
        f[i] = {f[i + 1].first + 1, i + 1};
        if (now == 0) continue;
        for (int j = i + 1; ; j++) {
            f[i] = min(f[i], {f[j].first + 1, j});
            if (j > n) break;
            now = now * 10 + s[j] - '0';
            if (now >= B) break;
        }
    }

    for (int i = 1; i <= n; i = f[i].second) {
        long long t = 0;
        for (int j = i; j < f[i].second; j++) t = t * 10 + s[j] - '0';
        ans = ans * B + t;
    }
    printf("%lld\n", ans);
    return 0;
}
