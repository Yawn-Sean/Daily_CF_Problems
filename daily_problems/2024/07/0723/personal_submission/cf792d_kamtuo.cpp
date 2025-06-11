/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-23 19:06 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

int main() {
    LL n;
    cin >> n;
    int q;
    cin >> q;
    while (q --) {
        LL now;
        LL k = n;
        string s;
        cin >> now >> s;
        LL sum = 0;
        vector<LL> v;
        while (now != (k + 1ll) / 2) {
            if (now < (k + 1ll) / 2) {
                v.push_back(0ll);
            } else {
                v.push_back((k + 1ll) / 2);
                now -= (k + 1ll) / 2;
            }
            k >>= 1;
        }
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == 'U') {
                if (v.size() == 0) continue;
                v.pop_back();
                now <<= 1;
            } else if (s[i] == 'R') {
                if (now == 1) continue;
                v.push_back(now);
                now >>= 1;
            } else {
                if (now == 1) continue;
                now >>= 1;
                v.push_back(0ll);
            }
        }
        for (int i = 0; i < v.size(); i ++) {
            now += v[i];
        }
        cout << now << endl;
    }
    return 0;
}

/*

*/
