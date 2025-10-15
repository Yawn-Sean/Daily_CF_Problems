#include  <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n;
long long K, A[MAXN + 5];

int main() {
    scanf("%d%lld", &n, &K);
    for (int i = 1; i < n; i++) scanf("%lld", &A[i]);

    long long ans = K;
    for (int i = 2; i + 1 < n; i++) {
        int l1 = 1, r1 = i - 1;
        while (l1 < r1) {
            int mid = (l1 + r1) >> 1;
            if (A[mid] >= A[i] - A[mid]) r1 = mid;
            else l1 = mid + 1;
        }

        int l2 = i + 1, r2 = n - 1;
        while (l2 < r2) {
            int mid = (l2 + r2) >> 1;
            if (A[mid] - A[i] >= K - A[mid]) r2 = mid;
            else l2 = mid + 1;
        }

        for (int dj = -1; dj <= 1; dj++) for (int dk = -1; dk <= 1; dk++) {
            int j = l1 + dj, k = l2 + dk;
            if (1 <= j && j < i && i < k && k < n) {
                long long mx = max({A[j], A[i] - A[j], A[k] - A[i], K - A[k]});
                long long mn = min({A[j], A[i] - A[j], A[k] - A[i], K - A[k]});
                ans = min(ans, mx - mn);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
