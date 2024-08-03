// 参考: https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/04/0430/personal_submission/cf747d_tsreaper.cpp
//
// 题解没看懂, 但蛙佬的这个解答相对好理解些.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const ll N = 2e5;
ll n, k, c, A[N + 10];

ll get(ll L, ll R, ll k) {
    vector<ll> vec;
    ll tot = 0;
    for (ll l = L, r = L; l <= R; l = r) {
        for (; l <= R && A[l] < 0; l++);
        if (l > R)
            break;
        for (r = l; r <= R && A[r] >= 0; r++);
        vec.push_back(r - l);
        tot += r - l;
    }
    k -= R - L + 1 - tot;
    if (k < 0)
        return n * 2 + 2;
    sort(vec.begin(), vec.end());
    for (ll i = 0; i < vec.size(); i++) {
        k -= vec[i];
        if (k < 0)
            return (vec.size() - i) * 2 + 1;
    }
    return 1;
}

int main() {
    scanf("%lld%lld", &n, &k); for (ll i = 1; i <= n; i++)
        scanf("%lld", A + i), c += A[i] >= 0;
    if (c == n)
        puts("0");
    else {
        ll L = 1, R = n;
        for (; A[L] >= 0; L++);
        for (; A[R] >= 0; R--);
        ll ans = R == n
            ? get(L, R, k)
            : min(get(L, R, k) + 1, get(L, R, k - (n - R)));
        printf("%lld", ans <= n ? ans : -1);
    }
    return 0;
}
