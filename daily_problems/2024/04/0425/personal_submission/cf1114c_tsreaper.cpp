#include <bits/stdc++.h>
#define SQRT ((int) 1e6)
using namespace std;

bool flag[SQRT + 10];
vector<int> prime;

int main() {
    for (int i = 2; i * i <= SQRT; i++) if (!flag[i]) for (int j = i * 2; j <= SQRT; j += i) flag[j] = true;
    for (int i = 2; i <= SQRT; i++) if (!flag[i]) prime.push_back(i);

    long long n, b;
    scanf("%lld%lld", &n, &b);

    auto gao = [&](long long x) {
        long long ret = 0;
        for (__int128 y = x; y <= n; y *= x) ret += n / y;
        return ret;
    };

    long long ans = 1e18;
    for (int p : prime) {
        if (p > b) break;
        if (b % p) continue;
        int cnt = 0;
        while (b % p == 0) b /= p, cnt++;
        ans = min(ans, gao(p) / cnt);
    }
    if (b > 1) ans = min(ans, gao(b));
    printf("%lld\n", ans);
    return 0;
}
