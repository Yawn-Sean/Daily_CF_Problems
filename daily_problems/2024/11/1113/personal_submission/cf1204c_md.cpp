// 1113
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, 1e9));
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        dist[i][i] = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') {
                dist[i][j] = 1;
            }
        }
    }

    int m;
    std::cin >> m;
    std::vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> p[i];
        --p[i];
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    std::vector<int> ret{p[0]};
    int curDist = 0;
    for (int i = 1; i < m; ++i) {
        curDist += dist[p[i - 1]][p[i]];
        if (curDist > dist[ret.back()][p[i]]) {
            ret.push_back(p[i - 1]);
            curDist = dist[ret.back()][p[i]];
        }
    }
    ret.push_back(p.back());

    std::cout << ret.size() << '\n';
    for (auto x : ret) {
        std::cout << x + 1 << ' ';
    }

    return 0;
}