#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    i64 pl, pr, vl, vr, k;
    cin >> pl >> pr >> vl >> vr >> k;

    vector<i64> nums;
    //先随便写一个dfs生成47数字
    function<void(int,int)> dfs = [&](int num_digit, i64 cur_num) {
        if (num_digit >= 10 || cur_num > 1e9) {
            return;
        } else {
            if (num_digit >= 1) {
                nums.push_back(cur_num);
            }
        }

        i64 num1 = cur_num * 10 + 4;
        i64 num2 = cur_num * 10 + 7;
        dfs(num_digit + 1, num1);
        dfs(num_digit + 1, num2);
    };

    dfs(0, 0);
    sort(nums.begin(), nums.end());

    /*
        维护一个长度为k的滑动窗口
        内部正好包括k个幸运数字
    */

    // 求区间[l1, r1]和[l2, r2]的交集长度
    auto get_intersection = [&](i64 l1, i64 r1, i64 l2, i64 r2) {
        return max(0ll, min(r1, r2) - max(l1, l2) + 1);
    };

    int n = nums.size();
    int l = 0, r = k - 1;
    i64 tot_pair = (pr - pl + 1) * (vr - vl + 1);
    i64 ok_pair = 0;

    for (; r < n; r++) {
        // 包含k个数字的最大区间
        i64 lo = (l > 0 ? (nums[l - 1] + 1) : 1);
        i64 hi = (r + 1 < n ? (nums[r + 1] - 1) : 1e9);
        // [lo, hi]区间为可行域
        // min(p, v) - max(p, v) 需要恰好落在lo hi之间
        i64 x1 = get_intersection(lo, nums[l], pl, pr);
        i64 y1 = get_intersection(nums[r], hi, vl, vr);

        i64 x2 = get_intersection(lo, nums[l], vl, vr);
        i64 y2 = get_intersection(nums[r], hi, pl, pr);

        ok_pair += x1 * y1 + x2 * y2;
        // 保证窗口大小为k
        l++; 
    }
    // cout << tot_pair << " " << ok_pair << endl;
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            if (pl <= nums[i] && nums[i] <= pr && vl <= nums[i] && nums[i] <= vr) {
                ok_pair--;
            }
        }
    }
    cout << fixed << setprecision(10) << min((long double)1.0, (long double)1.0 * ok_pair / tot_pair) << endl;
    return 0;
}
