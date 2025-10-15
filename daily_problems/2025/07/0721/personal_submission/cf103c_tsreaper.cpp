#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, K;
    int q;
    scanf("%lld%lld%d", &n, &K, &q);
    while (q--) {
        long long x; scanf("%lld", &x);
        if (K == 0) printf(".");
        else if (K <= n / 2) {
            if (n % 2 == 1) {
                if (x == n || (x % 2 == 0 && x >= n + 2 - K * 2)) printf("X");
                else printf(".");
            } else {
                if (x % 2 == 0 && x >= n + 1 - K * 2) printf("X");
                else printf(".");
            }
        } else {
            long long t = K - n / 2;
            if (x >= n + 1 - t * 2) printf("X");
            else if (x % 2 == 1) printf(".");
            else printf("X");
        }
    }
    printf("\n");
    return 0;
}
