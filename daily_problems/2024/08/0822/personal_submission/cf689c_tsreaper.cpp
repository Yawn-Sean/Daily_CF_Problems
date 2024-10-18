#include <bits/stdc++.h>
using namespace std;

long long calc(long long n) {
    long long ret = 0;
    for (long long K = 2, P = 8; P <= n; K++, P = K * K * K)
        ret += n / P;
    return ret;
}

int main() {
    long long m; scanf("%lld", &m);
    long long head = 1, tail = 1e16;
    while (head < tail) {
        long long mid = (head + tail) >> 1;
        if (calc(mid) >= m) tail = mid;
        else head = mid + 1;
    }
    if (calc(head) != m) printf("-1\n");
    else printf("%lld\n", head);
    return 0;
}
