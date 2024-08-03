#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y; scanf("%d%d%d", &n, &x, &y);
    while (n--) {
        int v; scanf("%d", &v);
        v %= x + y;
        if (v == 0) printf("Both\n");
        else {
            long long head = 1, tail = 1LL * x * y;
            while (head < tail) {
                long long mid = (head + tail) >> 1;
                long long tot = mid / x + mid / y;
                if (tot >= v) tail = mid;
                else head = mid + 1;
            }
            if (head % y == 0 && head % x > 0) printf("Vanya\n");
            else if (head % x == 0 && head % y > 0) printf("Vova\n");
            else printf("Both\n");
        }
    }
    return 0;
}
