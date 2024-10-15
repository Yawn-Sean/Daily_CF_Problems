/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-20 09:32 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector a(n, 0), ans(n, 0);
    vector<std::pair<int, int>> nums(n);
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n; i ++) {
        int a1 = n - a[i], a2 = a[(i + 1) % n];
        nums[i].first = a1 - a2;
        nums[i].second = i; 
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i ++) {
        ans[nums[i].second] = n - i - 1; 
    }
    for (int i = 0; i < n; i ++) cout << ans[i] << " \n"[i == n - 1];
    return 0;
}

#endif

/*

*/
