#include <bits/stdc++.h>
using namespace std;

void make_swap(int s, int e, int n, vector<pair<int, int>>& ops) {
    if (s > e) {
        swap(s, e);
    }

    if (e - s >= (n / 2)) {
        ops.emplace_back(s, e);
    } else if (s <= (n / 2) && e <= (n / 2)) {
        ops.emplace_back(s, n);
        ops.emplace_back(e, n);
        ops.emplace_back(s, n);
    } else if (s > (n / 2) && e > (n / 2)) {
        ops.emplace_back(s, 1);
        ops.emplace_back(e, 1);
        ops.emplace_back(s, 1);
    } else {
        ops.emplace_back(s, n);
        ops.emplace_back(e, 1);
        ops.emplace_back(n, 1);
        ops.emplace_back(s, n);
        ops.emplace_back(e, 1);
    }
}

void work() {
    int n; cin >> n;
    vector<int> nums(n + 1);
    vector<int> npos(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> nums[i];
        npos[nums[i]] = i;
    }

    vector<pair<int, int>> ops;
    for (int i = 1; i <= n; i ++) {
        if (nums[i] == i) {
            continue;
        }

        int apos = i;
        int bpos = npos[i];
        make_swap(apos, bpos, n, ops);

        swap(nums[apos], nums[bpos]);
        swap(npos[nums[apos]], npos[nums[bpos]]);
    }

    cout << ops.size() << "\n";
    for (auto [s, e] : ops) {
        cout << s << " " << e << "\n";
    }
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