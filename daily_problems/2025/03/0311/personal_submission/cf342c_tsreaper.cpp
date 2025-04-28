#include <bits/stdc++.h>
using namespace std;

int main() {
    long long r, h; scanf("%lld%lld", &r, &h);
    long long ans = h / r * 2;
    long long rem = h % r;
    if (rem >= sqrt(3) / 2 * r) ans += 3;
    else if (rem * 2 >= r) ans += 2;
    else ans++;
    printf("%lld\n", ans);
    return 0;
}
