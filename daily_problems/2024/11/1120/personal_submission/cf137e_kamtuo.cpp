/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-20 20:15 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string aeiou = "aeiouAEIOU";
    auto check = [&] (char now) -> bool {
        for (int i = 0; i < aeiou.size(); i ++) if (now == aeiou[i]) return false;
        return true;
    };
    string s;
    cin >> s;
    vector cnt(s.size() + 1, 0);
    for (int i = 0; i < s.size(); i ++){
        cnt[i + 1] = check(s[i]);
    }
    for (int i = 1; i <= s.size(); i ++) cnt[i] += cnt[i - 1];
    int maxl = 0;
    LL ans = 0;
    for (int i = 1; i <= s.size(); i ++) cnt[i] = 3 * cnt[i] - i;
    // for (int i = 1; i <= s.size(); i ++) cout << cnt[i] << ' ';
    // cout << "\n";
    vector<int> nums;
    nums.push_back(0);
    for (int i = 1; i <= s.size(); i ++) {
        int l = 0, r = (int)nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (cnt[nums[mid]] <= cnt[i]) r = mid;
            else l = mid + 1;
        }
        if (cnt[nums[r]] <= cnt[i]) {
            if (maxl < i - nums[r]) {
                maxl = i - nums[r];
                ans = 1;
            } else if (maxl == i - nums[r]) {
                ans ++;
            }
        } else {
            nums.push_back(i);
        }
    }
    if (maxl == 0) {
        cout << "No solution\n";
    } else {
        cout << maxl << ' ' << ans << "\n";
    }
    return 0;
}

#endif

/*

*/
