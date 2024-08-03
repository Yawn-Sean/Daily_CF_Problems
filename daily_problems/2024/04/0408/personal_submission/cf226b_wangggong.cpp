// 参考: https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/04/0408/solution/cf226b.md

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll N = 1e5;
ll n, a[N + 10], S[N + 10], ans[N + 10], t, x;

int main() {
    scanf("%lld", &n); for (ll i = 0; i < n; i++)
        scanf("%lld", a + i);
    sort(a, a + n);
    for (ll i = 0, j = n - 1; i < j; i++, j--)
        swap(a[i], a[j]);
    for (ll i = 0; i < n; i++)
        S[i + 1] = S[i] + a[i];
    for (ll i = 1; i <= n; i++)
        for (ll l = 1, c = i, w = 1; l < n; l += c, c *= i, w++)
            ans[i] += (S[min(l + c, n)] - S[l]) * w;
    scanf("%lld", &t); while (t--)
        scanf("%lld", &x), printf("%lld ", ans[min(x, n)]);
    return 0;
}
