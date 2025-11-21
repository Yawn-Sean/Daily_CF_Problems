#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        if (a > b) swap(a, b);
        if (a == b) {
            if ((a & 1) || (b & 1)) {
                printf("NO\n");
            } else {
                printf("SI\n");
            }
        } else if (b > 2 * a) {
            printf("NO\n");
        } else { // a >= b / 2
            if (a % (b - a) != 0) {
                printf("NO\n");
            } else {
                auto check = [&] (const int m) -> bool {
                    return b % m == 0 && a > b / m && b % (a - b / m) == 0;
                };
                if (check(2) || check(3) || check(4)) {
                    printf("SI\n");
                } else {
                    printf("NO\n");
                }
            }
        }
    }
    return 0;
}

