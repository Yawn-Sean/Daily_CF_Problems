/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-08 09:14 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    vector cnt(12345, 0);
    while (t --) {
        int n;
        cin >> n;
        vector a(n, 0);
        vector<int> nums;
        for (int i = 0; i < n; i ++) {
            cin >> a[i];
            cnt[a[i]] ++;
            if (cnt[a[i]] == 2) nums.push_back(a[i]);
        }
        int ans1 = 0, ans2 = 10000;
        for (int i = 0; i < n; i ++) {
            if (cnt[a[i]] >= 2) {
                if (cnt[a[i]] >= 4) {
                    ans1 = ans2 = a[i];
                }
            }
            cnt[a[i]] --;
        }
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i ++) {
            if ((1ll * ans1 * ans1 + 1ll * ans2 * ans2) * 1ll * nums[i] * nums[i - 1] > (1ll * nums[i] * nums[i] + 1ll * nums[i - 1] * nums[i - 1]) * 1ll * ans1 * ans2) {
                ans1 = nums[i];
                ans2 = nums[i - 1];
            }
        }
        cout << ans1 << ' ' << ans1 << ' ' <<  ans2 << ' ' << ans2 << "\n";
    }
    return 0;
}

#endif

/*

*/
