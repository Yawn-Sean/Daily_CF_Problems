/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-29 11:03 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector p(n + 1, vector (5, 0));
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 5; j ++) {
            cin >> p[i][j];
        }
    }
    vector<int> ans;
    if (n >= (1 << 5) + 5 + 2) {
        cout << 0 << endl;
    } else {
        for (int i = 1; i <= n; i ++) {
            bool ok = true;
            for (int j = 1; j <= n; j ++) {
                if (j == i) continue;
                for (int k = 1; k <= n; k ++) {
                    if (k == i || k == j) continue;
                    int res = 0;
                    for (int sk = 0; sk < 5; sk ++) {
                        res += (p[j][sk] - p[i][sk]) * (p[k][sk] - p[i][sk]);
                    }
                    if (res > 0) ok = false;
                }
            }
            if (ok) ans.push_back(i);
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i ++) {
            cout << ans[i] << "\n";
        }
    }
    return 0;
}

#endif

/*

*/
