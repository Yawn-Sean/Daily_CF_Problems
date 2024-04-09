#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

enum class Winner {
    Vanay, Vova, Both
};

i64 findMinTime(i64 x, i64 y, i64 num) {
    i64 lo = 0;
    i64 hi = 1e15;
    while (lo + 1 < hi) {
        auto mid = lo + (hi - lo) / 2;
        if (mid / x + mid / y >= num) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    if (hi / x + hi / y >= num) {
        return hi;
    } else {
        return lo;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x, y;
    std::cin >> n >> x >> y;

    vector<Winner> winners(n);
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        auto time = findMinTime(x, y, num);
        // vanay = 1/x * xy = y
        // vova = 1/y * xy = x
        if (time % x == 0 && time % y == 0) {
            winners[i] = Winner::Both;
        } else if (time % x == 0) {
            winners[i] = Winner::Vova;
        } else {
            winners[i] = Winner::Vanay;
        }
    }

    for (auto winner : winners) {
        if (winner == Winner::Vanay) {
            std::cout << "Vanya\n";
        } else if (winner == Winner::Vova) {
            std::cout << "Vova\n";
        } else {
            std::cout << "Both\n";
        }
    }

    return 0;
}