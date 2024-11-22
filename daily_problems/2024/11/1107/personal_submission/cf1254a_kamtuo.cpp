/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-07 10:36 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t --) {
        int r, c, k;
        cin >> r >> c >> k;
        vector mp(r, string());
        for (int i = 0; i < r; i ++) cin >> mp[i];
        int cnt = 0;
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                if (mp[i][j] == 'R') cnt ++;
            }
        }
        vector<int> nums;
        for (int i = 0; i < k; i ++) {
            nums.push_back(cnt / k);
        }
        for (int i = 0; i < cnt % k; i ++) {
            nums[i] ++;
        }
        vector idx = {0, 0, 1, -1}, idy = {1, -1, 0, 0};
        string ch = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        vector st(r, vector (c, 0));
        int now = 0;
        for (int x = 0; x < r; x ++) {
            if (x % 2 == 0) {
                for (int y = 0; y < c; y ++) {
                    st[x][y] = 1;
                    if (mp[x][y] == 'R') nums[now] --;
                    mp[x][y] = ch[now];
                    if (nums[now] == 0) now ++;
                    if (now == k) now = k - 1;
                }
            } else {
                for (int y = c - 1; y >= 0; y --) {
                    st[x][y] = 1;
                    if (mp[x][y] == 'R') nums[now] --;
                    mp[x][y] = ch[now];
                    if (nums[now] == 0) now ++;
                    if (now == k) now = k - 1;
                }
            }
        }
        for (int i = 0; i < r; i ++) {
            cout << mp[i] << "\n";
        }
    }
    return 0;
}

#endif

/*

*/
