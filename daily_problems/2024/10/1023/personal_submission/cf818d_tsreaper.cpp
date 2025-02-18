#include <bits/stdc++.h>
#define MAXA ((int) 1e6)
using namespace std;

int cnt[MAXA + 10];
bool bad[MAXA + 10];

int main() {
    int n, K; scanf("%d%d", &n, &K);
    bad[K] = true;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (x == K) tot++;
        else {
            if (cnt[x] - tot < 0) bad[x] = true;
            cnt[x]++;
        }
    }
    for (int i = 1; i <= MAXA; i++) if (!bad[i] && cnt[i] - tot >= 0) { printf("%d\n", i); return 0; }
    printf("-1\n");
    return 0;
}
