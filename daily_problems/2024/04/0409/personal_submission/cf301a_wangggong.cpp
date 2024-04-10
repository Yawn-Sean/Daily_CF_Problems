#include <iostream>

using namespace std;
typedef long long ll;
const ll MAXN = 0x3f3f3f3f;
ll n, m, a, neg, mn = MAXN, ans;

int main() {
    scanf("%lld", &n); m = n * 2 - 1; while (m--) {
        scanf("%lld", &a), ans += abs(a), mn = min(mn, abs(a));
        if (a < 0)
            neg++;
    }
    printf("%lld", ans - 2 * ((n % 2 == 0 && neg % 2) ? mn : 0));
    return 0;
}
