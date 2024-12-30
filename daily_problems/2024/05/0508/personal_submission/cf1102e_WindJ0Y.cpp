#include <bits/stdc++.h>
using namespace std;

void work() {
    int n; cin >> n;

    map<int, int> min_pos, max_pos;

    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        if (min_pos.count(t)) {
            max_pos[t] = i;
        } else {
            min_pos[t] = i;
        }
    }

    vector<int> c_ans(n + 1);
    for (auto [v, max_p] : max_pos) {
        int min_p = min_pos[v];
        c_ans[min_p + 1] --;
        c_ans[max_p + 1] ++;
    }

    int ans = 0;
    int cur_v = 0;
    for (int i = 1; i <= n - 1; i++) {
        cur_v += c_ans[i];
        if (cur_v == 0) {
            ans ++;
        }
    }

    long long out = 1;
    while (ans --) {
        out *= 2;
        out %= 998244353;
    } 

    cout << out << "\n";
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