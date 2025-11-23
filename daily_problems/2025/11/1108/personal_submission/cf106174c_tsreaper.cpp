#include <bits/stdc++.h>
#define MAXP 20
using namespace std;

long long n, K;
__int128 P[MAXP + 1];

__int128 gao(long long x) {
    if (x == 0) return 0;

    __int128 ret = 0;
    for (int i = 1; i <= MAXP; i++) {
        if (P[i] <= x) ret += (P[i] - P[i - 1]) * i;
        else {
            ret += (x - P[i - 1] + 1) * i;
            break;
        }
    }
    return ret;
}

__int128 calc(long long x) {
    return gao(x + n - 1) - gao(x - 1);
}

int main() {
    P[0] = 1;
    for (int i = 1; i <= MAXP; i++) P[i] = P[i - 1] * 10;

    scanf("%lld%lld", &n, &K);
    long long head = 1, tail = 1e18;
    while (head < tail) {
        long long mid = (head + tail) >> 1;
        if (calc(mid) >= K) tail = mid;
        else head = mid + 1;
    }
    if (calc(head) == K) printf("%lld\n", head);
    else printf("-1\n");
    return 0;
}
