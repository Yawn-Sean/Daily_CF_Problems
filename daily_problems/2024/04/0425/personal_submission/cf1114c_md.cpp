#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void primeFactors(i64 n, std::map<i64, i64>& factors)
{
    while (n % 2 == 0) {
        factors[2]++;
        n >>= 1;
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors[i]++;
            n = n / i;
        }
    }

    if (n > 2) {
        factors[n]++;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, b;
    std::cin >> n >> b;
    
    map<i64, i64> factors;
    primeFactors(b, factors);

    i64 ret = 1e18;
    for (auto[prime, cnt] : factors) {
        i64 cur = 0;
        i64 num = n;
        while (num) {
            cur += num / prime;
            num /= prime;
        }
        ret = min(ret, cur / cnt);
    }
    cout << ret << '\n';

    return 0;
}