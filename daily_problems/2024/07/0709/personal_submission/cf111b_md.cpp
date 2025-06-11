// 0709
#include <bits/stdc++.h>
using namespace std;

std::vector<int> minp, primes; 
constexpr int V = 1E5;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(V);
    auto get_factors = [&](int x) {
        std::vector<int> ret{1};
        while (x > 1) {
            int p = minp[x];
            int k = ssize(ret);
            while (x % p == 0) {
                for (int i = 0; i < k; ++i) {
                    ret.push_back(ret[ssize(ret) - k] * p);
                }
                x /= p;
            }
        }
        return ret;
    };

    int n;
    std::cin >> n;

    std::vector<int> last_visited(V + 1, -1);
    for (int i = 0; i < n; ++i) {
        int x;
        int y;
        std:cin >> x >> y;

        auto factors = get_factors(x);
        int ret = 0;
        for (auto factor : factors) {
            if (i - last_visited[factor] > y) {
                ++ret;
            }
            last_visited[factor] = i;
        }

        std::cout << ret << '\n';
    }
    return 0;
}