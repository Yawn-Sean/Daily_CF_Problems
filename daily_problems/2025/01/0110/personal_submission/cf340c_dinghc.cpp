#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    long long s1 = 0;
    for (auto& x : a) {
        scanf("%d", &x);
        s1 += x;
    }
    ranges::sort(a);
    long long s2 = 0, cur = a[0];
    for (int i = 1; i < n; i++) {
        s2 += 1LL * i * a[i] - cur;
        cur += a[i];
    }
    long long s = s1 + 2 * s2;
    int g = gcd(s, n);
    printf("%lld %d\n", s / g, n / g);
    return 0;
}

