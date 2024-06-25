#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    std::cin >> n;
    vector<int> cat(n);
    copy_n(istream_iterator<int>(cin), n, begin(cat));
    map<int, int> freq;

    for (auto x : cat) {
        ++freq[x];
    }
    
    vector<int> freq_vec;
    for (auto [_, f] : freq) {
        freq_vec.push_back(f);
    }

    auto min_freq = *min_element(begin(freq_vec), end(freq_vec));

    int ret = n;
    for (int i = 1; i <= min_freq; ++i) {
        bool found = true;
        int cnt = 0;
        for (auto f : freq_vec) {
            auto cur = (f + i) / (i + 1);
            if (i * cur > f) {
                found = false;
                break;
            }
            cnt += cur;
        }

        if (found) {
            ret = min(ret, cnt);
        }
    }
    cout << ret << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}