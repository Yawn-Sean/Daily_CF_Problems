#include <bits/stdc++.h>
#define MAGIC 50
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long x, long long y) {
    return uniform_int_distribution<long long>(x, y)(rng);
}

long long n;
int K;

bool query(long long L, long long R) {
    printf("%lld %lld\n", L, R); fflush(stdout);
    char s[5]; scanf("%s", s);
    if (s[0] == 'Y') return true;
    else return false;
}

int main() {
    scanf("%lld%d", &n, &K);
    long long L = 1, R = n;
    while (true) {
        if (R - L >= MAGIC) {
            long long mid = (L + R) / 2;
            if (query(L, mid)) {
                L = max(1LL, L - K);
                R = min(n, mid + K);
            } else {
                L = max(1LL, mid + 1 - K);
                R = min(n, R + K);
            }
        } else {
            long long x = rnd(L, R);
            if (query(x, x)) {
                break;
            } else {
                L = max(1LL, L - K);
                R = min(n, R + K);
            }
        }
    }
    return 0;
}
