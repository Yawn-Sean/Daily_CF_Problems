#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll N = 2e5;
ll n, m, A[N + 10], B[N + 10], op, r;
vector<pll> V;

int main() {
    scanf("%lld%lld", &n, &m); for (ll i = 1; i <= n; i++)
        scanf("%lld", A + i);
    stack<pll> S;
    S.push({-1, N + 10});
    while (m--) {
        scanf("%lld%lld", &op, &r);
        for (; S.top().second <= r; S.pop());
        S.push({op, r});
    }
    for (; S.size() > 1; V.push_back(S.top()), S.pop());
    ll mx = V.back().second;
    // 这里的处理方式需要注意一下
    for (ll i = 1; i <= mx; i++)
        B[i] = A[i];
    sort(B + 1, B + mx + 1);
    ll p = 1, q = mx;
    for (ll i = V.size() - 1; i >= 0; i--)
        for (ll j = V[i].second, k = i ? V[i - 1].second : 0; j > k; j--)
            A[j] = V[i].first == 1 ? B[q--] : B[p++];
    for (ll i = 1; i <= n; i++)
        printf("%lld ", A[i]);
    return 0;
}
