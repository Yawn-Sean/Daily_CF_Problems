#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n;
long long ans, A[MAXN + 5], B[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        int s = sqrt(x);

        A[i] = x;
        for (int j = s; j <= s + 1; j++) A[i] = min(A[i], abs(x - 1LL * j * j));

        if (s * s == x) {
            if (x == 0) B[i] = 2;
            else B[i] = 1;
        } else {
            B[i] = 0;
        }
    }

    for (int i = 1; i <= n; i++) ans += A[i];
    vector<int> det;
    for (int i = 1; i <= n; i++) det.push_back(B[i] - A[i]);
    sort(det.begin(), det.end());
    for (int i = 0; i < n / 2; i++) ans += det[i];
    printf("%lld\n", ans);
    return 0;
}
