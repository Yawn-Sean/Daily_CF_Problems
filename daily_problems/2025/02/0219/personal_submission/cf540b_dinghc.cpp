#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, p, x, y;
    scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
    vector<int> a(k);
    int s = 0;
    for (auto& i : a) {
        scanf("%d", &i);
        s += i;
    }
    ranges::sort(a);
    int less = ranges::lower_bound(a, y) - a.begin();
    if (less > n / 2) {
        printf("-1\n");
    } else {
        if (y > 1) {
            int m = min(n / 2 - less, n - k);
            s += m;
            s += (n - k - m) * y;
            if (s <= x) {
                for (int i = 0; i < m; i++) printf("1 ");
                for (int i = 0; i < n - k - m; i++) printf("%d ", y);
            } else {
                printf("-1\n");
            }
        } else {
            s += n - k;
            if (s <= x) {
                for (int i = 0; i < n - k; i++) printf("1 ");
            } else {
                printf("-1\n");
            }
        }
    }
    return 0;
}

