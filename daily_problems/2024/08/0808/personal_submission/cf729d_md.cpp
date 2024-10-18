// 0808
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, a, b, k;
    std::cin >> n >> a >> b >> k;
    std::string board;
    std::cin >> board;

    std::vector<int> segs;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (board[i] == '1') {
            cur = 0;
        } else {
            ++cur;
            if (cur == b) {
                segs.push_back(i);
                cur = 0;
            }
        }
    }

    std::cout << size(segs) - a + 1 << '\n';
    for (int i = a - 1; i < size(segs); ++i) {
        std::cout << segs[i] + 1 << " \n"[i + 1 == size(segs)];
    }

    return 0;
}