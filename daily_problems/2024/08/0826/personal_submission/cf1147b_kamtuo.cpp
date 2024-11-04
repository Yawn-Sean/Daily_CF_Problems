/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-26 20:06 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector len(n + 1, vector<int> ());
    vector st(n + 1, 0);
    for (int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        if (x > y) std::swap(x, y);
        if (y - x > n / 2) {
            len[((x - y) % n + n) % n].push_back(y);
            len[((x - y) % n + n) % n].push_back(x);
        } else {
            len[y - x].push_back(x);
            len[y - x].push_back(y);
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (len[i].size()) {
            len[i].push_back(n);
            sort(len[i].begin(), len[i].end());
            // debug("i:", i, "len:", len[i]);
        }
    }
    int t = n;
    vector<int> nums;
    for (int i = 2; i <= n; i ++) {
        if (t % i == 0) {
            while (t % i == 0) t /= i;
            nums.push_back(n / i);
        }
    }
    // debug("nums:", nums);
    for (int i = 0; i < nums.size(); i ++) {
        int now = nums[i];
        bool ok = true;
        for (int j = 1; j <= n; j ++) {
            for (int k = 0; k < (int)len[j].size() - 1; k ++) {
                int f = lower_bound(len[j].begin(), len[j].end(), (len[j][k] + now) % n) - len[j].begin();
                if (len[j][f] != ((len[j][k] + now) % n)) {
                    ok = false;
                    // debug("now:", now, "k:", len[j][k], "f:", len[j][f], "j:", j);
                }
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

#endif

/*

*/
