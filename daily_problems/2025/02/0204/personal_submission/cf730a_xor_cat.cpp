#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

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

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto check = [&]() {
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                return false;
            }
        }
        return true;
    };

    std::vector<std::vector<int>> ans;
    int cnt = 0;
    while (!check()) {
        cnt++;
        std::set<int> p;
        int max1 = std::ranges::max(a);
        for (int i = 0; i < n; i++) {
            if (p.size() == 5) {
                break;
            }
            if (a[i] == max1) {
                p.insert(i);
            }
        }
        int max2 = -1, pos = -1;
        if (p.size() < 2) {
            for (int i = 0; i < n; i++) {
                if (a[i] != max1 && chmax(max2, a[i])) {
                    pos = i;
                }
            }
        } else {
            if (p.size() % 2) { // 3 5
                while (p.size() != 3) {
                    p.erase(p.begin());
                }
            } else {
                while (p.size() != 2) {
                    p.erase(p.begin());
                }
            }
        }
        std::vector<int> tmp;
        for (int i = 0; i < n; i++) {
            if (p.contains(i) || i == pos) {
                if (a[i] > 0) a[i]--;
                tmp.push_back(1);
            } else {
                tmp.push_back(0);
            }
        }
        ans.push_back(tmp);
    }

    std::cout << a[0] << "\n";
    std::cout << ans.size() << "\n";
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            std::cout << ans[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}
