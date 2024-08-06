#include <bits/stdc++.h>
using namespace std;

long long calc(long long lim) {
    long long ret = 0;
    long long p = 1;
    for (int len = 1; p <= lim; p *= 10, len++) {
        if (p * 10 <= lim) ret += p * 9 * len;
        else ret += (lim - p + 1) * len;
    }
    return ret;
}

int main() {
    long long n;
    scanf("%lld", &n);

    long long head = 1, tail = n;
    while (head < tail) {
        long long mid = (head + tail) >> 1;
        if (calc(mid) >= n) tail = mid;
        else head = mid + 1;
    }

    int det = calc(head) - n;
    long long x = head;
    while (det--) x /= 10;
    printf("%lld\n", x % 10);
    return 0;
}
