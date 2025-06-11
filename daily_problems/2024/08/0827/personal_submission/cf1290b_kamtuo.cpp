/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-27 10:50 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    int q, n;
    cin >> s >> q;
    n = s.size();
    vector cnt(26, vector (n + 1, 0));
    for (int i = 1; i <= n; i ++) {
        cnt[s[i - 1] - 'a'][i] = 1;
        for (int j = 0; j < 26; j ++) {
            cnt[j][i] += cnt[j][i - 1];
        }
    }
    for (int i = 1; i <= q; i ++) {
        int l, r;
        cin >> l >> r;
        if (r - l + 1 == 1) {
            cout << "Yes" << endl;
            continue;
        }
        int col = 0;
        for (int j = 0; j < 26; j ++) {
            if (cnt[j][r] - cnt[j][l - 1]) col ++;
        }
        if (col > 2) {
            cout << "Yes" << endl;
        } else {
            if (col >= 2) {
                if (s[l - 1] != s[r - 1]) cout << "Yes" << endl;
                else {
                    cout << "No" << endl;
                }
            } else {
                cout << "No" << endl;
            }
        }
    } 
    return 0;
}

#endif

/*

*/
