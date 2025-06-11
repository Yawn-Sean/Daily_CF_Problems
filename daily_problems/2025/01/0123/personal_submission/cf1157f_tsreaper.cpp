#include <bits/stdc++.h>
#define MAXA ((int) 2e5)
using namespace std;

int n, ans, L, R;
int cnt[MAXA + 5], f[MAXA + 5];

void update(int tot, int l, int r) {
    if (tot <= ans) return;
    ans = tot; L = l; R = r;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }

    for (int i = 1, j = 1; i <= MAXA + 1; i++) {
        f[i] = f[i - 1] + cnt[i];

        if (cnt[i] > 0) {
            update(cnt[i], i, i);
            if (cnt[i + 1] > 0) update(cnt[i] + cnt[i + 1], i, i + 1);
        }

        if (cnt[i] < 2) {
            if (i != j) {
                int tot = f[i - 1] - f[j - 1];
                int l = j, r = i - 1;
                if (cnt[j - 1] > 0) tot += cnt[j - 1], l--;
                if (cnt[i] > 0) tot += cnt[i], r++;
                update(tot, l, r);
            }
            j = i + 1;
        }
    }

    printf("%d\n", ans);
    for (int i = 1; i <= cnt[L]; i++) printf("%d ", L);
    if (L == R) { printf("\n"); return 0; }
    for (int i = L + 1; i < R; i++) printf("%d ", i);
    for (int i = 1; i <= cnt[R]; i++) printf("%d ", R);
    for (int i = R - 1; i > L; i--) for (int j = 1; j < cnt[i]; j++) printf("%d ", i);
    printf("\n");
    return 0;
}
