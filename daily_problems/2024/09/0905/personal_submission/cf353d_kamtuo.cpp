/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-05 10:27 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int cm = -1, cf = -1;
    LL ans = 0;
    s.insert(s.begin(), 'F');
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == 'F') cf = i;
    }
    for (int i = 0; i < cf; i ++) {
        if (s[i] == 'M') cm = i;
    }
    int to = 0;
    if (cf == -1 || cm == -1) {
        cout << 0 << "\n";
    } else {
        while (cm != -1) {
            if (ans < cf - cm - 1 + to) ans += cf - cm - 1 + to - ans;
            to += cf - cm - 1;
            cf = cm + 1;
            while (s[cf - 1] == 'M') {
                ans ++;
                cf --;
            } 
            int now = -1;
            for (int i = cf - 1; i >= 0; i --) {
                if (s[i] == 'M') {
                    now = i;
                    break;
                }
            }
            cm = now;
        }
        cout << ans << "\n";
    }
    return 0;
}

#endif

/*

*/
