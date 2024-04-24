#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    vector<int> nodes(n);
    copy_n(istream_iterator<int>(cin), n, begin(nodes));
    double ret = 0.0;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u, --v;
        ret = max(ret, ((double)nodes[u] + nodes[v]) / (double)w);
    }

    cout << fixed << setprecision(10) << ret << '\n';
    return 0;
}