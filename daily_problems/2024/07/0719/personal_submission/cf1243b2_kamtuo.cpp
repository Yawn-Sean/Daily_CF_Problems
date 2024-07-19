/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-19 11:52 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

int main() {
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector<std::pair<int, int>> ans;
        bool ok = true;
        for (int i = 0; i < n - 1; i ++) {
            bool find = false;
            if (a[i] != b[i]) {
                for (int j = i + 1; j < n; j ++) {
                    if (b[j] == b[i]) {
                        ans.push_back({i, j});
                        std::swap(a[i], b[j]);
                        find = true;
                        break;
                    }
                }
                if (find == false)
                for (int j = i + 1; j < n; j ++) {
                    if (a[j] == b[i]) {
                        ans.push_back({j, i + 1});
                        std::swap(a[j], b[i + 1]);
                        ans.push_back({i, i + 1});
                        std::swap(a[i], b[i + 1]);
                        find = true;
                        break;
                    }
                }
                if (find == false) ok = false;
            }
        }
        if (a[n - 1] != b[n - 1]) ok = false;
        if (ok) {
            cout << "Yes" << endl;
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i ++) {
                cout << ans[i].first + 1 << ' ' << ans[i].second  + 1 << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}

/*

*/
