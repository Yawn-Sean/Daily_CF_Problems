/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-12 18:44 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m;
    cin >> m;
    string s;
    cin >> s;
    int n = s.size();
    char now = 'a';
    for (char ch = 'a'; ch <= 'z'; ch ++) {
        bool ok = true;
        vector<int> pos = {-1, n};
        for (int i = 0; i < n; i ++) if (s[i] <= ch) pos.push_back(i);
        sort(pos.begin(), pos.end());
        for (int i = 1; i < pos.size(); i ++) {
            if (pos[i] - pos[i - 1] > m) ok = false;
        }
        if (ok) {
            now = ch;
            break;
        }
    }
    vector<int> pos = {-1, n};
    vector<char> ans;
    for (int i = 0; i < n; i ++) {
        if (s[i] < now) {
            ans.push_back(s[i]);
            pos.push_back(i);
        }
    }
    sort(pos.begin(), pos.end());
    for (int i = 1; i < pos.size(); i ++) {
        if (pos[i] - pos[i - 1] > m) {
            int l = pos[i - 1] + 1, r = pos[i] - 1;
            while (r - l + 1 >= m) {
                int k = l;
                for (int j = 0; j < m && l + j <= r; j ++) {
                    if (now == s[l + j]) k = max(k, l + j);
                }
                ans.push_back(now);
                // debug("l:", l);
                l = k + 1;
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i ++) cout << ans[i];
    // cout << now << endl;
    return 0;
}

#endif

/*

*/
