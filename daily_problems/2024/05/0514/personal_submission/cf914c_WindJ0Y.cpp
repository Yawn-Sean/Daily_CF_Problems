#include <bits/stdc++.h>
using namespace std;

void work() {

    int MOD = 1e9 + 7;

    vector<int> num_ans(1005);
    for (int i = 2; i <= 1000; i ++) {
        num_ans[i] = num_ans[__builtin_popcount(i)] + 1;
    }

    string str_bin_n; cin >> str_bin_n;
    int k; cin >> k;

    if (k == 0) {
        cout << 1 << endl;
        return;
    }
    if (k == 1) {
        cout << str_bin_n.size() - 1 << endl;
        return;
    }

    vector<int> cnt(1005);
    int pre_one_cnt = 0;
    for (auto c : str_bin_n) {
        for (int i = cnt.size() - 1; i > 0; i --) {
            cnt[i] = (cnt[i] + cnt[i - 1]) % MOD;
        }
        if (c == '1') {
            cnt[pre_one_cnt] = (cnt[pre_one_cnt] + 1) % MOD;
            pre_one_cnt ++;
        }
    }

    int ans = 0;
    for (int i = 0; i <= 1000; i ++) {
        if (num_ans[i] == k - 1) {
            ans = (ans + cnt[i]) % MOD;
        }
    }
    if (num_ans[pre_one_cnt] == k - 1) {
        ans = (ans + 1) % MOD;
    }

    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}