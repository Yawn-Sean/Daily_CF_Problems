#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAGIC ((int) 1e6)
using namespace std;

int n, ans;
long long A[MAXN + 10];

int f[MAGIC + 10], cnt[MAGIC + 10];

int main() {
    cnt[0] = 1;
    int mx = 0;
    for (int i = 4, l = 2, r = 2; i <= MAGIC; i++) {
        while (1LL * (r + 1) * (r + 1) <= i) {
            cnt[f[r + 1]]++;
            r++;
        }
        while (1LL * l * l * l * l < i) {
            cnt[f[l]]--;
            l++;
        }
        for (int j = 0; ; j++) if (cnt[j] == 0) { f[i] = j; break; }
        mx = max(mx, f[i]);
    }

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    sort(A + 1, A + n + 1);

    for (int i = 0; i <= mx; i++) cnt[i] = 0;
    cnt[0] = 1;
    for (int i = 1, l = 2, r = 2; i <= n; i++) if (A[i] >= 4) {
        while (1LL * (r + 1) * (r + 1) <= A[i]) {
            cnt[f[r + 1]]++;
            r++;
        }
        while (1LL * l * l * l * l < A[i]) {
            cnt[f[l]]--;
            l++;
        }
        for (int j = 0; ; j++) if (cnt[j] == 0) { ans ^= j; break; }
    }
    if (ans) printf("Furlo\n");
    else printf("Rublo\n");
    return 0;
}
