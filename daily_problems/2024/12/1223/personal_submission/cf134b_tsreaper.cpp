#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii gcd(int a, int b) {
    if (b == 0) return {a, -1};
    pii p = gcd(b, a % b);
    return {p.first, p.second + a / b};
}

int main() {
    int n; scanf("%d", &n);
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        pii p = gcd(n, i);
        if (p.first == 1) ans = min(ans, p.second);
    }
    printf("%d\n", ans);
    return 0;
}
