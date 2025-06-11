#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll B = 32;
ll x, d, cur = 1;
std::vector<ll> ans;

int main() {
    scanf("%lld%lld", &x, &d);
    while (x) {
        if (x <= 5) {
            for (; x; x--)
                ans.push_back(cur), cur += d + 1;
            continue;
        }
        for (ll b = B; b >= 0; b--)
            if ((x >> b) & 1) {
                for (ll i = 0; i < b; i++)
                    ans.push_back(cur);
                cur += d + 1;
                x -= (1ll << b) - 1;
            }
    }
    printf("%zu\n", ans.size());
    for (auto v: ans)
        printf("%lld ", v);
    return 0;
}
