// 0826
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    std::vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
        --nums[i];
        pos[nums[i]] = i;
    }

    std::vector<int> primes;
    std::vector<bool> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 0; i <= std::min(500, n); i ++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    std::vector<int> divs(n + 1);
    for (int i = 4; i <= n; i += 2) {
        for (auto prime : primes) {
            if (isPrime[i - prime]) {
                divs[i] = prime;
                break;
            }
        }
    }

    std::vector<std::pair<int, int>> swaps;
    auto do_swap = [&](int x, int y) {
        std::swap(nums[x], nums[y]);
        std::swap(pos[nums[x]], pos[nums[y]]);
        swaps.emplace_back(x, y);
    };

    for (int x = 0; x < n; ++x) {
        if (pos[x] == x) {
            continue;
        }

        int y = pos[x];
        if (isPrime[y - x + 1]) {
            do_swap(x, y);
        } else {
            if ((y - x) % 2 == 0) {
                int v = y - x + 2;
                do_swap(x + divs[v] - 1, y);
                do_swap(x, x + divs[v] - 1);
            } else {
                int nx = x + 1;
                int v = y - nx + 2;
                do_swap(nx + divs[v] - 1, y);
                do_swap(nx, nx + divs[v] - 1);
                do_swap(x, nx);
            }
        }
    }
 
    std::cout << size(swaps) << '\n';
    for (auto[x, y] : swaps) {
        std::cout << x + 1 << ' ' << y + 1 << '\n';
    }

    return 0;
}