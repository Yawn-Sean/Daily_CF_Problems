/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-05 11:11 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t --) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<Node> big, small, e;
        vector p(n + 1, 0);
        int t = -0x3f3f3f3f;
        std::function<int(int)> find = [&] (int x) -> int {
            if (x - p[x]) p[x] = find(p[x]);
            return p[x];
        };
        for (int i = 1; i <= n; i ++) {
            p[i] = i;
        }
        for (int i = 1; i <= m; i ++) {
            int u, v;
            cin >> u >> v;
            int c;
            cin >> c;
            e.push_back({u, v, c});
            if (abs(t - k) > abs(c - k)) t = c;
        }
        LL res = 0;
        for (int i = 0; i < e.size(); i ++) {
            if (e[i].c <= k) small.push_back(e[i]);
            else big.push_back(e[i]);
        }
        sort(small.begin(), small.end());
        sort(big.begin(), big.end());
        int tot = 1;
        LL ans1 = 0x3f3f3f3f3f3f3f3f, ans2 = 0x3f3f3f3f3f3f3f3f;
        if (small.size()) {
            int fu = find(small.back().u), fv = find(small.back().v);
            p[fu] = fv;
            for (int i = 0; i < small.size(); i ++) {
                if (tot == n - 1) break;
                int fu = find(small[i].u), fv = find(small[i].v);
                if (fu - fv) {
                    p[fu] = fv;
                    tot ++;
                }
            }
            if (tot == n - 1) ans1 = abs(small.back().c - k);
            else ans1 = 0;
            for (int i = 0; i < big.size(); i ++) {
                if (tot == n - 1) break;
                int fu = find(big[i].u), fv = find(big[i].v);
                if (fu - fv) {
                    p[fu] = fv;
                    tot ++;
                    ans1 += big[i].c - k;
                }
            }
        }
        if (big.size()) {
            tot = 1;
            for (int i = 1; i <= n; i ++) p[i] = i;
            int fu = find(big[0].u), fv = find(big[0].v);
            p[fu] = fv;
            ans2 = big[0].c - k;
            for (int i = 0; i < small.size(); i ++) {
                if (tot == n - 1) break;
                int fu = find(small[i].u), fv = find(small[i].v);
                if (fu - fv) {
                    p[fu] = fv;
                    tot ++;
                }
            }
            for (int i = 0; i < big.size(); i ++) {
                if (tot == n - 1) break;
                int fu = find(big[i].u), fv = find(big[i].v);
                if (fu - fv) {
                    p[fu] = fv;
                    tot ++;
                    ans2 += big[i].c - k;
                }
            }
        }
        // debug("ans1:", ans1, "ans2:", ans2);
        cout << min(ans1, ans2) << endl;
    }
    return 0;
}

#endif

/*

*/
