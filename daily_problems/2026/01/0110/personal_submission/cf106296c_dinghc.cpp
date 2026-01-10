#include <bits/stdc++.h>

using namespace std;

int query(int t, int x) {
    printf("%d %d\n", t, x + 1);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        auto check = [&] (int x) -> int {
            if (x == 0) return 0;
            if (x == n - 1) return 1;
            int bx = query(2, x);
            int ax = query(1, x + 1);
            return ax == bx ? 0 : 1;
        };
        int lo = 1, hi = n / 2 - 1;
        while (lo <= hi) {
            int mid = (hi + lo) / 2;
            if (check(mid * 2)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        printf("3 %d %d\n", lo * 2 - 1, lo * 2 + 1);
        fflush(stdout);
    }
    return 0;
}

