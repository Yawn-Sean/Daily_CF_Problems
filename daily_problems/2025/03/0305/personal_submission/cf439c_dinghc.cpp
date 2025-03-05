#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);
    vector<int> a[2]{};
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        a[x & 1].push_back(x);
    }
    int s = a[0].size(), t = a[1].size();
    if (k - p > t || t % 2 != (k - p) % 2) {
        printf("NO\n");
        return 0;
    }
    if (s + (t - k + p) / 2 < p) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    int i = 0, j = 0;
    for (; i < k - p - (p == 0); i++) {
        printf("1 %d\n", a[1][i]);
    }
    if (p > 0) {
        for (; j < min(p - 1, s); j++) {
            printf("1 %d\n", a[0][j]);
        }
        for (int l = min(p - 1, s); l < p - 1; l++, i += 2) {
            printf("2 %d %d\n", a[1][i], a[1][i + 1]);
        }
    }
    printf("%d ", n - i - j);
    for (; i < t; i++) printf("%d ", a[1][i]);
    for (; j < s; j++) printf("%d ", a[0][j]);
    return 0;
}

