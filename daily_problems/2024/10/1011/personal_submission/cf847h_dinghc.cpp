#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
int a[N];
long long fw[N + 1];
long long bw[N + 1];
long long pref[N + 1];
long long suff[N + 1];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    pref[0] = 0;
    fw[0] = 0;
    for (int i = 0; i < n; i++) {
        fw[i + 1] = max(fw[i] + 1, (long long)a[i]);
        pref[i + 1] = pref[i] + fw[i + 1] - a[i];
    }
    suff[n] = 0;
    bw[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        bw[i] = max(bw[i + 1] + 1, (long long)a[i]);
        suff[i] = suff[i + 1] + bw[i] - a[i];
    }
    long long ans = min(suff[0], pref[n]);
    for (int i = 1; i < n - 1; i++) {
        ans = min(ans, pref[i + 1] + suff[i] - min(fw[i + 1], bw[i]) + a[i]);
    }
    printf("%lld\n", ans);
    return 0;
}

