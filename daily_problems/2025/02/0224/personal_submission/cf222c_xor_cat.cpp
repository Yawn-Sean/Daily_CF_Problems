#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

std::vector<int> minp, primes;
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

constexpr int N = 1E7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(N);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::map<int, int> cnt[2];
    auto decomp = [&](int x, int k) {
        while (x > 1) {
            int p = minp[x];
            x /= p;
            cnt[k][p]++;
        }
    };

    for (int i = 0; i < n; i++) {
        decomp(a[i], 0);
    }
    for (int i = 0; i < m; i++) {
        decomp(b[i], 1);
    }

    for (auto &[x, y] : cnt[0]) {
        if (cnt[1].contains(x)) {
            y = std::min(cnt[1][x], y);
            cnt[1][x] = y;
        } else {
            y = 0;
        }
    }
    for (auto &[x, y] : cnt[1]) {
        if (!cnt[0].contains(x)) {
            y = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int x = a[i];
        while (x > 1) {
            int p = minp[x];
            if (cnt[0][p]) {
                a[i] /= p;
                cnt[0][p]--;
            }
            x /= p;
        }
    }

    for (int i = 0; i < m; i++) {
        int x = b[i];
        while (x > 1) {
            int p = minp[x];
            if (cnt[1][p]) {
                b[i] /= p;
                cnt[1][p]--;
            }
            x /= p;
        }
    }

    std::cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < m; i++) {
        std::cout << b[i] << " \n"[i == m - 1];
    }

    return 0;
}
