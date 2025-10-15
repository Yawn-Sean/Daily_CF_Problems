/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2025-03-18 14:11                         */
/* Software : Visual Studio Code                            */
/*                                                          */
/*  ██╗  ██╗ █████╗ ███╗   ███╗████████╗██╗   ██╗ ██████╗   */
/*  ██║ ██╔╝██╔══██╗████╗ ████║╚══██╔══╝██║   ██║██╔═══██╗  */
/*  █████╔╝ ███████║██╔████╔██║   ██║   ██║   ██║██║   ██║  */
/*  ██╔═██╗ ██╔══██║██║╚██╔╝██║   ██║   ██║   ██║██║   ██║  */
/*  ██║  ██╗██║  ██║██║ ╚═╝ ██║   ██║   ╚██████╔╝╚██████╔╝  */
/*  ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝   ╚═╝    ╚═════╝  ╚═════╝   */
/*----------------------------------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, w, h;
    cin >> n >> w >> h;
    struct Node {
        int g;
        int x, t;
        int i;
        bool operator < (const Node& now) const {
            if (x - t != now.x - now.t) return x - t < now.x - now.t;
            return x > now.x;
        };
    };
    const int IDX = 123456;
    vector<Node> vi, hr;
    vector<vector<Node>> xt(IDX << 1);
    vector<std::pair<int, int>> ans(n + 1);
    for (int i = 1; i <= n; i ++) {
        int g, x, t;
        cin >> g >> x >> t;
        xt[x - t + IDX].push_back({g, x, t, i});
    }
    for (int i = 0; i < (IDX << 1); i ++) {
        if (xt[i].size()) {
            vector<Node> now = xt[i];
            sort(xt[i].begin(), xt[i].end(), [] (Node x1, Node x2) {
                if (x1.g != x2.g) return x1.g > x2.g; 
                if (x1.g == 2) return x1.x > x2.x;
                return x1.x < x2.x;
            });
            sort(now.begin(), now.end(), [] (Node x1, Node x2) {
                if (x1.g != x2.g) return x1.g < x2.g;
                if (x1.g == 1) return x1.x < x2.x;
                return x1.x > x2.x;
            });
            for (int j = 0; j < now.size(); j ++) {
                if (now[j].g == 1) {
                    ans[xt[i][j].i].first = now[j].x;
                    ans[xt[i][j].i].second = h;
                } else {
                    ans[xt[i][j].i].first = w;
                    ans[xt[i][j].i].second = now[j].x;
                }
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
    return 0;
}

#endif

/*

*/
