#include <bits/stdc++.h>

using namespace std;
long long a[100];

bool solve(int n, long long p, long long q) {
    if (n > 1 && a[n - 1] == 1) {
        a[n - 2] += 1;
        n -= 1;
    }
    for (int i = 0; i < n; i++) {
        if (q == 0) return false;
        long long x = p / q;
        long long r = p % q;
        if (x != a[i]) return false;
        p = q, q = r;
    }
    return q == 0;
}

int main() {
    long long p, q;
    scanf("%I64d%I64d", &p, &q);
    long long g = gcd(p, q);
    p /= g;
    q /= g;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
    }
    if (solve(n, p, q)) printf("YES\n");
    else printf("NO\n");
    return 0;
}

