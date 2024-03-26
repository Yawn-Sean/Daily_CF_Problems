#include <iostream>

using namespace std;
typedef long long ll;
const ll N = 1e6;
ll n, x, tr[N + 10], P;

ll lowBit(ll n) {
    return n & -n;
}

ll query(ll k) {
    ll ans = 0;
    for (; k; k -= lowBit(k))
        ans += tr[k];
    return ans;
}

void add(ll k, ll v) {
    for (; k <= n; k += lowBit(k))
        tr[k] += v;
}

int main() {
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &x), add(x, 1), P += i - query(x);
    puts(!((P & 1) ^ (n & 1)) ? "Petr" : "Um_nik");
    return 0;
}
