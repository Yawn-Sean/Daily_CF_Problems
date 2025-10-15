#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using real = long double;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    real P;
    std::cin >> N >> P;

    for (int i = 0; i <= N; i++) {
        real cur = 0;
        cur += 0.5 * (i * (N - i) * (N - i - 1)) / 2;
        cur += (i * (i - 1)) / 2 * (N - i);
        cur += (i * (i - 1) * (i - 2)) / 6;
        if ((cur / (N * (N - 1) * (N - 2) / 6)) >= P) {
            std::cout << i << "\n";
            return 0;
        }
    }
    
    return 0;
}
