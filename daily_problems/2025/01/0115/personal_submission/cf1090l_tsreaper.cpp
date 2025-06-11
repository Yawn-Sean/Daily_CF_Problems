#include <bits/stdc++.h>
using namespace std;

int m, n, a, b, K;

bool check1(long long x) {
    if (a >= b) {
        int rem = max(0, K - (n + 1) / 2);
        return (rem * x + b - 1) / b <= n / 2;
    } else {
        int rem = max(0, K - n / 2);
        return (rem * x + a - 1) / a <= (n + 1) / 2;
    }
}

bool check2(long long x) {
    long long tot = a + b;
    long long y = (K * x + tot - 1) / tot;
    if (n >= y * 2) return true;
    if (n <= (y - 1) * 2) return false;
    return tot * (y - 1) + a >= K * x;
}

int main() {
    scanf("%d%d%d%d%d", &m, &n, &a, &b, &K);
    if (K > n) { printf("0\n"); return 0; }
    
    long long head = min(a, b), tail = max(a, b);
    while (head < tail) {
        long long mid = (head + tail + 1) >> 1;
        if (check1(mid)) head = mid;
        else tail = mid - 1;
    }
    if (m <= head || head < max(a, b)) { printf("%lld\n", min(1LL * m, head)); return 0; }

    head = max(a, b); tail = m;
    while (head < tail) {
        long long mid = (head + tail + 1) >> 1;
        if (check2(mid)) head = mid;
        else tail = mid - 1;
    }
    printf("%lld\n", head);
    return 0;
}
