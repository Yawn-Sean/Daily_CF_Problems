/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-09 09:57 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b, c;
    cin >> a >> b >> c;
    vector cnta(26, 0), cntb(26, 0), cntc(26, 0);
    for (int i = 0; i < a.size(); i ++) cnta[a[i] - 'a'] ++;
    for (int i = 0; i < b.size(); i ++) cntb[b[i] - 'a'] ++;
    for (int i = 0; i < c.size(); i ++) cntc[c[i] - 'a'] ++;
    int ans = 0;
    for (int i = 0; i <= a.size(); i ++) {
        int res = 1000000;
        bool ok = true;
        for (int j = 0; j < 26; j ++) {
            if (1ll * i * cntb[j] > cnta[j]) {
                ok = false;
                break;
            }
            if (cntc[j]) {
                res = min(1ll * res, (cnta[j] - 1ll * i * cntb[j]) / cntc[j]);
            }
        }
        if (ok == false) continue;
        ans = max(ans, i + res);
    }
    for (int i = 0; i <= a.size(); i ++) {
        int res = 1000000;
        bool ok = true;
        for (int j = 0; j < 26; j ++) {
            if (1ll * i * cntb[j] > cnta[j]) {
                ok = false;
                break;
            }
            if (cntc[j]) {
                res = min(1ll * res, (cnta[j] - 1ll * i * cntb[j]) / cntc[j]);
            }
        }
        if (ok == false) continue;
        if (res + i == ans) {
            for (int j = 1; j <= res; j ++) cout << c;
            for (int j = 1; j <= i; j ++) cout << b;
            for (int j = 0; j < 26; j ++) {
                cnta[j] -= cntb[j] * i + cntc[j] * res;
                while (cnta[j] --) {
                    cout << (char)(j + 'a');
                }
            }
        }
    }
    return 0;
}

#endif

/*

*/
