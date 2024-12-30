// 0617
#include <bits/stdc++.h>

using i64 = long long;
constexpr int MOD = 1000000007;

std::vector<int> ZAlgo(const std::string& s) {
    int n = size(s);
    std::vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = std::max(std::min(r - i, z[i - l]), 0);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::string p;
    std::cin >> p;
    std::vector<int> pos(m);
    std::copy_n(std::istream_iterator<int>(std::cin), m, begin(pos));
    std::transform(begin(pos), end(pos), begin(pos), [](auto x) { return x - 1;});

    std::vector<int> z = ZAlgo(p);

    for (int i = 1; i < m; ++i) {
        int idx = pos[i] - pos[i - 1];
        if (idx >= size(p)) {
            continue;
        }

        if (z[idx] + idx != size(p)) {
            std::cout << 0 << '\n';
            return 0;
        }
    }

    std::vector<int> diff(n + 1);
    for (auto cur_pos : pos) {
        diff[cur_pos]++;
        diff[cur_pos + ssize(p)]--;
    }

    i64 ret = 1;
    for (int i = 0; i < n; ++i) {
        if (diff[i] == 0) {
            ret = (ret * 26) % MOD;
        }
        diff[i + 1] += diff[i];
    }

    std::cout << ret << '\n';
    return 0;
}