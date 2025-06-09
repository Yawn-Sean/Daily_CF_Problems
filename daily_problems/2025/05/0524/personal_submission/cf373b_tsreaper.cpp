#include <bits/stdc++.h>
#define MAXP 18
using namespace std;

long long P[MAXP + 1];

__int128 calc(long long x) {
    if (x == 0) return 0;
    __int128 ret = 0;
    for (int i = 1; ; i++) {
        if (P[i] > x) {
            ret += i * (x - P[i - 1] + 1);
            return ret;
        } else {
            ret += i * (P[i] - P[i - 1]);
        }
    }
}

int main() {
    P[0] = 1;
    for (int i = 1; i <= MAXP; i++) P[i] = P[i - 1] * 10;

    long long W, M, K; scanf("%lld%lld%lld", &W, &M, &K);
    if ((calc(M) - calc(M - 1)) * K > W) printf("0\n");
    else {
        long long head = M, tail = 2e16;
        while (head < tail) {
            long long mid = (head + tail + 1) >> 1;
            if ((calc(mid) - calc(M - 1)) * K <= W) head = mid;
            else tail = mid - 1;
        }
        printf("%lld\n", head - M + 1);
    }
    return 0;
}
