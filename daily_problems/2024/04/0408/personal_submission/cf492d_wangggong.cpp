#include <iostream>

using namespace std;
typedef long long ll;
ll t, x, y, a, g;

ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x % y);
}

ll get() {
    if (a % (x + y) == 0)
        return 0;
    a %= x + y;
    ll p = 0, q = x * y + 1;
    while (p < q) {
        ll mid = (p + q) >> 1;
        if (mid / y + mid / x >= a)
            q = mid;
        else
            p = mid + 1;
    }
    return p % x == 0 && p % y == 0 ? 0 : p % x == 0 ? -1 : 1;
}

int main() {
    scanf("%lld%lld%lld", &t, &x, &y), g = gcd(x, y), x /= g, y /= g;
    while (t--)
        scanf("%lld", &a), g = get(), puts(g == 1 ? "Vanya" : g == -1 ? "Vova" : "Both");
    return 0;
}
