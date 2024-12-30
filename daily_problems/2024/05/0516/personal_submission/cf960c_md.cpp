// 0516
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, d;
    std::cin >> x >> d;

    vector<i64> ret;
    i64 cur = 1;
    for (int ele_cnt = 31; ele_cnt > 0; --ele_cnt) {
        auto seq_cnt = (1 << ele_cnt) - 1;
        while (x >= seq_cnt) {
            ret.insert(end(ret), ele_cnt, cur);
            cur += d;
            x -= seq_cnt;
        }
    }

    cout << size(ret) << endl;
    for (int i = 0; i < size(ret); ++i) {
        cout << ret[i] << " \n"[i == size(ret) - 1];
    }

    return 0;
}