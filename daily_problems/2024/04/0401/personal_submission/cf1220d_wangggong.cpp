#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
const ll N = 2e5;
ll n, a[N + 10], mx = -1;
unordered_map<ll, ll> m;

int main() {
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++)
        scanf("%lld", a + i), m[a[i] & -a[i]]++;
    for (auto [k, v] : m)
        if (mx == -1 || v > m[mx])
            mx = k;
    printf("%lld\n", n - m[mx]);
    for (ll i = 0; i < n; i++)
        if ((a[i] & -a[i]) != mx)
            printf("%lld ", a[i]);
    return 0;
}
