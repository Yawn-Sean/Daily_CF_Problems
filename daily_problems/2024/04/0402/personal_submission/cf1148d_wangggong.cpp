#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll N = 3e5;
ll n, a, b, c;
pll A[2 * N + 10];

int main() {
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld%lld", &a, &b), c += a < b, A[b] = {a < b ? 1 : -1, i};
    printf("%lld\n", max(c, n - c));
    if (c >= n - c) {
        for (ll i = 2 * n; i > 0; i--)
            if (A[i].first == 1)
                printf("%lld ", A[i].second);
    } else {
        for (ll i = 1; i <= 2 * n; i++)
            if (A[i].first == -1)
                printf("%lld ", A[i].second);
    }
    return 0;
}
