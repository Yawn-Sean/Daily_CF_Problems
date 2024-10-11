/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-23 09:38 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector st(12, 0);
    int now = 0;
    int ch = 0;
    int en = ch;
    for (int i = 1; i <= n; i ++) {
        string op;
        int x;
        cin >> op >> x;
        if (op == "&") {
            ch &= x;
            for (int j = 0; j < 10; j ++) {
                if ((x >> j) % 2 == 0) {
                    st[j] = 1;
                    now &= 1023 - (1 << j);
                }
            }
        } else if (op == "|") {
            ch |= x;
            for (int j = 0; j < 10; j ++) {
                if ((x >> j) & 1) {
                    st[j] = 1;
                    now |= (1 << j);
                } 
            }
        } else {
            ch ^= x;
            now ^= x;
        }
    }
    int ans1 = 1023, ans2 = 0, ans3 = now;
    for (int j = 0; j < 10; j ++) {
        if (st[j]) {
            ans3 &= 1023 - (1 << j);
            if ((now >> j) & 1) ans2 += (1 << j);
            else ans1 -= (1 << j); 
        }
    }
    cout << 3 << endl;
    cout << "&" << ' ' << ans1 << endl;
    cout << "|" << ' ' << ans2 << endl;
    cout << "^" << ' ' << ans3 << endl;
    return 0;
}

#endif

/*

*/
