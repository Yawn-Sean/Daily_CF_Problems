/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-15 18:55 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    bool ok = false;
    p --;
    for (int i = n - 1; i >= 0; i --) {
        string now = s;
        if (s[i] - 'a' == p) continue;
        bool no = true;
        for (int j = 1; s[i] - 'a' + j <= p; j ++) {
            bool yes = true;
            // debug("cn:", (char)(s[i] + j));
            if (i - 1 >= 0 && s[i - 1] == s[i] + j) yes = false;
            if (i - 2 >= 0 && s[i - 2] == s[i] + j) yes = false;
            if (yes) {
                now[i] = s[i] + j;
                no = false;
                break;
            }
        }
        if (!no) {
            bool now_ok = true;
            for (int j = i + 1; j < n; j ++) {
                bool check = false;
                for (int k = 0; k <= p; k ++) {
                    bool yes = true;
                    if (j - 1 >= 0 && now[j - 1] == k + 'a') yes = false; 
                    if (j - 2 >= 0 && now[j - 2] == k + 'a') yes = false; 
                    if (yes) {
                        now[j] = k + 'a';
                        check = true;
                        break;
                    }
                }
                if (check == false) {
                    now_ok = false;
                    break;
                }
            }
            if (now_ok) {
                cout << now << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}

#endif

/*

*/
