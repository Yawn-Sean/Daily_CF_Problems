#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
const ll N = 2e5;
ll t, n, k, l[N + 10], r[N + 10], q, x, d[N + 10];
char s[N + 10];

int main() {
    scanf("%lld", &t); while (t--) {
        memset(d, 0, sizeof d);
        scanf("%lld%lld%s", &n, &k, s + 1);
        for (ll i = 0; i < k; i++)
            scanf("%lld", l + i);
        for (ll i = 0; i < k; i++)
            scanf("%lld", r + i);
        scanf("%lld", &q); while (q--) {
            scanf("%lld", &x);
            ll i = 0; for (; r[i] < x; i++);
            ll y = l[i] + r[i] - x;
            if (x > y)
                swap(x, y);
            d[x]++, d[y + 1]--;
        }
        for (ll i = 0; i < n; i++)
            d[i + 1] += d[i];
        for (ll i = 0; i < k; i++)
            for (ll p = l[i], q = r[i]; p < q; p++, q--)
                if (d[p] % 2)
                    swap(s[p], s[q]);
        puts(s + 1);
    }
    return 0;
}
