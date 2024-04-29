#include <iostream>

using namespace std;
typedef long long ll;
const ll N = 3e5, MAXN = 0x3f3f3f3f;
ll n, I[N + 10][2], prefix[N + 10][2], sl = -MAXN, sr = MAXN, ans;

int main() {
    scanf("%lld", &n); for (ll i = 0; i < n; i++)
        scanf("%lld%lld", I[i], I[i] + 1);
    prefix[0][0] = -MAXN, prefix[0][1] = MAXN;
    for (ll i = 0; i < n; i++)
        prefix[i + 1][0] = max(prefix[i][0], I[i][0]), prefix[i + 1][1] = min(prefix[i][1], I[i][1]);
    for (ll i = n - 1; i >= 0; i--)
        ans = max(ans, min(sr, prefix[i][1]) - max(sl, prefix[i][0])), sl = max(sl, I[i][0]), sr = min(sr, I[i][1]);
    printf("%lld", ans);
    return 0;
}
