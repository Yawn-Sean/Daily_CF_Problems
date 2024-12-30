#include <bits/stdc++.h>

using namespace std;
constexpr int N = 200'000;
int a[N];
int suffix[N + 1];
int prefix[N + 1];

int main() {
    int n, k, x;
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] | a[i - 1];
    }
    suffix[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1] | a[i];
    }
    int ans = 0;
    int b = 1;
    for (int i = 0; i < k; i++) {
        b *= x;
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, prefix[i] | a[i] * b | suffix[i + 1]);
    }
    printf("%d\n", ans);
    return 0;
}

