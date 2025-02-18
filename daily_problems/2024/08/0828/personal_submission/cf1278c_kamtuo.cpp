/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-28 18:43 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    struct Node {
        int val;
        int i;
        bool operator < (const Node& now) const {
            return val < now.val;
        }
    };
    while (t --) {
        int n;
        cin >> n;
        vector a((n << 1) + 2, 0);
        for (int i = 1; i <= n * 2; i ++) {
            cin >> a[i];
            if (a[i] == 2) a[i] = -1;
        }
        int ans = 2 * n;
        vector<Node> v;
        v.push_back({0x3f3f3f3f, 0});
        for (int i = 1; i <= n; i ++) {
            a[i] += a[i - 1];
            v.push_back({a[i], i});
            if (a[i] == 0) ans = min(n - i + n, ans);
        }
        a[2 * n + 1] = 0;
        sort(v.begin(), v.end(), [] (Node a, Node b) {if (a.val != b.val) return a.val < b.val;return a.i > b.i;});
        for (int i = 2 * n; i > n; i --) {
            a[i] += a[i + 1];
            if (a[i] == 0) {
                ans = min(i - 1, ans);
            }
            int l = 0, r = (int)v.size() - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (v[mid].val >= -a[i]) r = mid;
                else l = mid + 1;
            }
            if (v[r].val == -a[i]) {
                ans = min(ans, n - v[r].i + i - n - 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

#endif

/*

*/
