#include <iostream>

typedef long long ll;
ll n, m, ans;

ll get(ll k) {
    return n / m + (n % m >= k) - (k == 0);
}

int main() {
    scanf("%lld%lld", &n, &m);
    for (ll i = 0; i < m; i++)
        for (ll j = 0; j < m; j++)
            if ((i * i + j * j) % m == 0)
                ans += get(i) * get(j);
    printf("%lld", ans);
    return 0;
}
