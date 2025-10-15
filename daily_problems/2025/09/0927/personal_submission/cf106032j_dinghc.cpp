#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1e6;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, q;
        scanf("%d %d %d", &n, &m, &q);
        vector<int> a(n);
        vector<int> cnt(m + 1, 0);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            cnt[a[i]] ^= 1;
        }
        int R = INF;
        for (int i = 1; i < m; i++) {
            if (cnt[i] == 1) {
                R = i;
                break;
            }
        }
        vector<int> steps(m + 1);
        steps[m] = cnt[m] == 1 ? 0 : R;
        for (int i = m - 1; i >= 1; i--) {
            if (cnt[i] == 1) {
                steps[i] = 0;
            } else {
                steps[i] = steps[i + 1] + 1;
            }
        }
        for (int i = 0, step = 0, type, idx; i < q; i++) {
            scanf("%d", &type);
            if (type == 1) {
                step += 1;
            } else {
                scanf("%d", &idx);
                int x = a[idx - 1];
                if (cnt[x] == 1) {
                    printf("%d\n", x);
                } else {
                    printf("%d\n", (x + min(steps[x], step) - 1) % m + 1);
                }
            }
        }
    }
    return 0;
}

