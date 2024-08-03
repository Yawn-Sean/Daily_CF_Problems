#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, k, x; cin >> n >> k >> x;

    vector<long long> nums(n);
    bool is_neg = false;

    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
        if (nums[i] < 0) {
            is_neg = !is_neg;
        }
    }

    if (!is_neg) {
        int mpos = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (abs(nums[i]) < abs(nums[mpos])) {
                mpos = i;
            }
        }
        long long ori_v = nums[mpos];
        long long delta = (ori_v >= 0 ? -x : x);
        long long mk = delta / abs(delta);
        while (ori_v * mk <= 0 && k) {
            ori_v += delta;
            k --;
        }
        nums[mpos] = ori_v;
    }

    if (k) {
        priority_queue<pair<long long, int>> to_bmp;
        for (int i = 0; i < n; i ++) {
            to_bmp.emplace(-abs(nums[i]), i);
        }
        while (k --) {
            auto [tv, pos] = to_bmp.top();
            to_bmp.pop();
            long long ori_v = nums[pos];
            if (ori_v >= 0) {
                ori_v += x;
            } else {
                ori_v -= x;
            }
            nums[pos] = ori_v;
            to_bmp.emplace(-abs(ori_v), pos);
        }
    }

    for (auto v : nums)  {
        cout << v << " ";
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