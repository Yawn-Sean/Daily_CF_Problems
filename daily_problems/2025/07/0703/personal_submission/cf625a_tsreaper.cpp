#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, b, c; scanf("%lld%lld%lld%lld", &n, &a, &b, &c);
    long long cnt = 0;
    if (n >= b) {
        long long x = n - b + 1, det = b - c;
        cnt = (x + det - 1) / det;
        cnt += (n - cnt * det) / a;
    }
    printf("%lld\n", max(n / a, cnt));
    return 0;
}
