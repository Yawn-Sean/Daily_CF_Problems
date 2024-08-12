/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-12 17:39 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

int main() {
    int n, k;
    cin >> n >> k;
    std::function<void(int, int)> test = [&] (int u, int v) {
        cout << u + v << endl;
    };
    vector<std::pair<int, int>> pii;
    vector<int> nums;
    for (int i = 1; i <= n; i ++) {
        int u, v;
        cin >> u >> v;
        pii.push_back({u, v});
        nums.push_back(u);
        nums.push_back(v);
    }
    sort(nums.begin(), nums.end());
    int len = unique(nums.begin(), nums.end()) - nums.begin();
    std::function<int (int)> find = [&] (int x) {
        return lower_bound(nums.begin(), nums.begin() + len, x) - nums.begin();
    };
    vector<vector<std::pair<int, int>>> l(len, vector<std::pair<int, int>>());
    for (int i = 0; i < n; i ++) {
        int now = find(pii[i].first);
        l[now].push_back({pii[i].second, i});
    }
    priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pri;
    int ans = 0;
    for (int i = 0; i < len; i ++) {
        for (int j = 0; j < l[i].size(); j ++) {
            if (pri.size() < k) pri.push({l[i][j].first, l[i][j].second});
            else {
                std::pair<int, int> now = pri.top();
                pri.pop();
                if (now.first < l[i][j].first) now = l[i][j];
                pri.push(now);
            }
        }
        if (pri.size() >= k) {
            ans = max(ans, pri.top().first - nums[i] + 1);
        }
    }
    vector<bool> st(n + 1, false);
    while (!pri.empty()) pri.pop();
    for (int i = 0; i < len; i ++) {
        for (int j = 0; j < l[i].size(); j ++) {
            if (pri.size() < k) pri.push({l[i][j].first, l[i][j].second});
            else {
                std::pair<int, int> now = pri.top();
                pri.pop();
                if (now.first < l[i][j].first) now = l[i][j];
                pri.push(now);
            }
        }
        if (pri.size() >= k) {
            if (ans == pri.top().first - nums[i] + 1) {
                cout << ans << endl;
                while (!pri.empty()) {
                    cout << pri.top().second + 1 << " ";
                    pri.pop();
                }
                return 0;
            }
        }
    }

    cout << ans << endl;
    for (int i = 1; i <= k; i ++) cout << i << " ";
    return 0;
}

/*

*/
