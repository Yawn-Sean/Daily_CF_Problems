#include <iostream>

using namespace std;
typedef long long ll;
const ll N = 1e5;
ll n, f[N + 10], ans;

int main() {
    scanf("%lld", &n); for (ll i = 0; i < n; i++)
        scanf("%lld", f + i);
    f[0] = f[n - 1] = 1;
    for (ll i = 1; i < n; i++)
        f[i] = min(f[i], f[i - 1] + 1);
    for (ll i = n - 2; i >= 0; i--)
        f[i] = min(f[i], f[i + 1] + 1);
    for (ll i = 0; i < n; i++)
        ans = max(ans, f[i]);
    printf("%lld", ans);
    return 0;
}
