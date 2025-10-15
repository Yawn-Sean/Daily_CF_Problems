#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5;
int a[N];
int d[N*2], f[N*2];

int solve(int n, int m, int k) {
    sort(a, a + n);
    sort(d, d + m);
    sort(f, f + k);
    int mx1 = 0, mx2 = 0;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        int t = a[i] - a[i - 1];
        if (t >= mx1) {
            mx2 = mx1;
            mx1 = t;
            l = a[i - 1];
            r = a[i];
        } else if (t > mx2) {
            mx2 = t;
        }
    }
    if (mx1 == mx2) return mx1;
    int res = mx1;
    int target = (r - l) / 2 + l;
    for (int i = 0, j = k - 1; i < m; i++) {
        while (j && d[i] + f[j] > target) {
            j--;
        }
        if (d[i] + f[j] < r && d[i] + f[j] > l) {
            res = min(res, max(r - d[i] - f[j], d[i] + f[j] - l));
        }
        if (j + 1 < k) {
            if (d[i] + f[j + 1] < r && d[i] + f[j + 1] > l) {
                res = min(res, max(r - d[i] - f[j + 1], d[i] + f[j + 1] - l));
            }
        }
    }
    return max(res, mx2);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &d[i]);
        }
        for (int i = 0; i < k; i++) {
            scanf("%d", &f[i]);
        }
        int ans = solve(n, m, k);
        printf("%d\n", ans);
    }
    return 0;
}

