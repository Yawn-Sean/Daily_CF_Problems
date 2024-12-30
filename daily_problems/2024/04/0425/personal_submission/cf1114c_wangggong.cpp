#include <iostream>
#include <climits>

using namespace std;
typedef long long ll;
ll n, b;

ll get(ll n, ll b) {
    ll ans = LLONG_MAX;
    for (ll i = 2; i <= b / i; i++)
        if (!(b % i)) {
            ll c = 0;
            for (; !(b % i); b /= i, c++);
            ll cur = 0;
            for (ll v = n; v; )
                v /= i, cur += v;
            ans = min(ans, cur / c);
        }
    if (b > 1) {
        ll cur = 0;
        for (ll v = n; v; )
            v /= b, cur += v;
        ans = min(ans, cur);
    }
    return ans;
}

int main() {
    scanf("%lld%lld", &n, &b), printf("%lld", get(n, b));
    return 0;
}
