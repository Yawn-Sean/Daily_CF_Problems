#include <bits/stdc++.h>

using namespace std;
using li = long long;

li factorials[2000]{1};
 
li fact(int m) {
    if (factorials[m]) return factorials[m];
    return factorials[m] = m * fact(m - 1);
}

li subfact(int m) {
    li res = 0LL;
    for (int i = 0, sgn = 1; i <= m; i++, sgn = -sgn) {
        res += sgn * fact(m) / fact(i);
    }
    return res;
}

li comb(int n, int k) {
    k = min(n - k, k);
    if (k == 0) return 1;
    li res = 1LL;
    for (int i = 0; i < k; i++) {
        res *= n - i;
        res /= i + 1;
    }
    return res;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    li ans = 0LL;
    for (int m = 0; m <= k; m++) {
        ans += comb(n, m) * subfact(m);
    }
    printf("%lld\n", ans);
    return 0;
}

