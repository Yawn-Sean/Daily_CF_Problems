#include <bits/stdc++.h>

#define ranges std::ranges
using i64 = long long;
std::vector<int> prime, minp;

void sieve(int n = 50) {
    minp.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = i;
            prime.push_back(i);
        }
        for (auto j : prime) {
            if (j > minp[i] || j > n / i) break;
            minp[i * j] = j;
        }
    }
}

bool isprime(int n) {
    return minp[n] == n;
}

std::vector<i64> pri(1, 1);
void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(51);
    for (int i = 1;i <= n;i++) {
        int x;  std::cin >> x;
        a[x] = 1;
    }

    for (auto x : pri) {
        int f = 0;
        for (int i = 1;i <= 50;i++)
        {
            if (a[i] && std::gcd(i, x) == 1) {
                f = 1;
                break;
            }
        }
        if (f) continue;
        else {
            std::cout << x;
            return;
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;

    sieve();

    for (auto x : prime) {
        int sz = pri.size();
        for (int i = 0;i < sz;i++)
            pri.push_back(pri[i] * x);
    }

    ranges::sort(pri);

    while (t--) {
        solve();
        std::cout << '\n';
    }
}