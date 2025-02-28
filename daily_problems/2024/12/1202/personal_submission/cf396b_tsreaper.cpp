#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n;
vector<char> vec[MAXN + 5];

bool prime(int x) {
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return false;
    return true;
}

void solve() {
    int n; scanf("%d", &n);
    long long x, y;
    for (x = n; !prime(x); x--);
    for (y = n + 1; !prime(y); y++);
    long long u = (x - 2) * y + (n - x + 1) * 2;
    long long v = 2 * x * y;
    long long g = gcd(u, v);
    u /= g; v /= g;
    printf("%lld/%lld\n", u, v);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
