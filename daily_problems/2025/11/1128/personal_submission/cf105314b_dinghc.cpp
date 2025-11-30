#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int N = 2e5;
int a[N];
int64 pre[N + 1];

int64 solve(int n, int64 m) {
    sort(a, a + n);
    auto check = [&] (int v) -> bool {
        int64 cnt = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (a[i] - a[j] >= v) {
                j++;
            }
            if (i > j) cnt += i - j;
        }
        return 1LL * (n - 1) * n - cnt * 2 < m;
    };
    int lo = 1, hi = 1e7;
    while (lo <= hi) {
        int mid = (hi + lo) / 2;
        if (check(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    int mth = lo - 1;
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }
    int64 ans = 0;
    int64 cnt = 0; 
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && a[j] - a[i] <= mth) {
            j++;
        }
        ans += 2LL * (pre[n] - pre[j]) - 2LL * (n - j) * a[i];
        cnt += 2LL * (n - j);
    }
    ans += (m - cnt) * mth;
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int64 m;
        scanf("%d %lld", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int64 ans = solve(n, m);
        printf("%lld\n", ans);
    }
    return 0;
}

