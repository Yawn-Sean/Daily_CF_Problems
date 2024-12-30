#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
int a[N], b[N];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    sort(a, a + n);
    sort(b, b + m);
    int cnt_a = 0, cnt_b = 0;
    bool ans = false;
    for (int i = n - 1, j = m - 1; i >= 0; i--) {
        cnt_a += 1;
        while (j >= 0 && b[j] >= a[i]) {
            j -= 1;
            cnt_b += 1;
        }
        if (cnt_a > cnt_b) {
            ans = true;
            break;
        }
    }
    if (ans) printf("YES\n");
    else printf("NO\n");
    return 0;
}

