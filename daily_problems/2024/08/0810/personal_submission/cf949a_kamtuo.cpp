/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-10 11:16 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector ans(n + 1, vector<int>());
    vector<int> one, zer;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '1') one.push_back(i);
        else zer.push_back(i);
    }
    if (one.size() >= zer.size()) {
        cout << -1 << endl;
        return 0;
    }
    vector ne(n + 1, -1);
    for (int i = 0; i < one.size(); i ++) {
        if (one[i] < zer[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int j = 0, i = 0; j < one.size(); j ++) {
        while (i < zer.size() && zer[i] < one[j]) i ++;
        if (i == zer.size()) {
            cout << -1 << endl;
            return 0;
        }
        ne[j] = i;
        i ++;
    }
    int res = 0;
    vector st(n + 1, 0);
    for (int i = 0; i < n; i ++) {
        if (st[i] == false) {
            st[i] = true;
            int now = i;
            // ans[i].push_back(i);
            while (now != -1) {
                st[now] = true;
                if (now < zer.size()) ans[i].push_back(zer[now]);
                if (now < one.size()) ans[i].push_back(one[now]);
                now = ne[now];
            } 
        }
    }
    for (int i = 0; i <= n; i ++) if (ans[i].size()) res ++;
    cout << res << endl;
    for (int i = 0; i <= n; i ++) {
        if (ans[i].size()) {
            cout << ans[i].size() << ' ';
            for (int j = 0; j < ans[i].size(); j ++) cout << ans[i][j] + 1 << ' ';
            cout << endl;
        }
    }
    return 0;
}

#endif

/*

*/
