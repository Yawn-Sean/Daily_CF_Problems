#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int N = 1E6 + 5;
constexpr int inf = 1E9;

template <typename T>
bool chmin(T &a, const T &b) {
    return b < a ? a = b, true : false;
}
template <typename T>
bool chmax(T &a, const T &b) {
    return b > a ? a = b, true : false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int X;
    std::cin >> X;

    std::vector<int> maxp(N);
    for (int i = 2; i < N; i++) {
        if (maxp[i] == 0) {
            for (int j = i; j < N; j += i) {
                maxp[j] = i;
            }
        }
    }

    int ans = inf;
    for (int i = X - maxp[X] + 1; i <= X - 1; i++) {
        if (maxp[i] != i) {
            chmin(ans, i - maxp[i] + 1);
        }
    }

    if (ans == inf) {
        std::cout << X - maxp[X] + 1 << "\n";
    } else {
        std::cout << ans << "\n";
    }

    return 0;
}
