// 1010
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> p(n);
    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        --p[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    int cycleCnt = 0;
    std::vector<int> visited(n, 0);
    for (int i = 0; i < n; ++i) {
        int cycleCur = i;
        if (!visited[cycleCur]) {
            while (!visited[p[cycleCur]]) {
                visited[p[cycleCur]] = 1;
                cycleCur = p[cycleCur];
            }

            ++cycleCnt;
        }
        assert(cycleCur == i);
    }

    auto flipCnt = std::accumulate(begin(b), end(b), 1, std::bit_xor<int>());
    if (cycleCnt == 1) {
        std::cout << flipCnt << '\n';
    } else {
        std::cout << cycleCnt + flipCnt << '\n';
    }

    return 0;
}