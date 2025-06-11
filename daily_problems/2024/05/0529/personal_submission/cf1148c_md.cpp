// 0529

#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<int> perm(n);
    copy_n(istream_iterator<int>(std::cin), n, begin(perm));
    transform(begin(perm), end(perm), begin(perm), [](int x) { return x - 1; });

    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[perm[i]] = i;
    }

    vector<pair<int, int>> outs;
    auto swap_pair = [&](int pos_a, int pos_b) {
        swap(perm[pos_a], perm[pos_b]);
        swap(pos[perm[pos_a]], pos[perm[pos_b]]);
        outs.emplace_back(pos_a + 1, pos_b + 1);
    };

    for (int i = 0; i < n / 2; ++i) {
        if (pos[i] == i) {
            continue;
        }

        if (pos[i] < n / 2) {
            swap_pair(pos[i], n - 1);
            swap_pair(n - 1, i);
        } else {
            swap_pair(pos[i], 0);
            swap_pair(0, n - 1);
            swap_pair(n - 1, i);
        }
    }

    for (int i = n - 1; i >= n / 2; --i) {
        if (pos[i] == i) {
            continue;
        }

        if (pos[i] < n / 2) {
            swap_pair(pos[i], n - 1);
            swap_pair(n - 1, 0);
            swap_pair(0, i);
        } else {
            swap_pair(pos[i], 0);
            swap_pair(0, i);
        }
    }

    if (pos[n - 1] != n - 1) {
        swap_pair(0, n - 1);
    }

    cout << size(outs) << endl;
    for (int i = 0; i < size(outs); ++i) {
        auto[from, to] = outs[i];
        cout << from << " " << to << endl;
    }

    return 0;
}