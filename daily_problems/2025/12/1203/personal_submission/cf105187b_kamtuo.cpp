/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2025-12-03 21:16                         */
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
    int n;
    cin >> n;
    const int N = 512345;
    vector p(N, vector<int>());
    vector to(2 * n + 1, vector<int> ());
    vector s(2 * n, 0);
    for (int i = 1; i <= 2 * n; i ++) {
        int now;
        cin >> now;
        s[i - 1] = now;
        p[now].push_back(i - 1);
    } 
    vector ans(n * 2, 0);
    vector cal(n * 2, 0);
    for (int i = 1; i <= n; i ++) {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    // cout << 1 << "\n";
    int now = 0;
    for (int i = N - 1; i >= 3; i --) {
        for (int j = i - 2; j <= i - 1; j ++) {
            for (int k = 0; k < p[j].size(); k ++) {
                cal[p[j][k]] = 1;
                cal[to[p[j][k]][0]] = 1;
            }
        }
        int cnt = 0;
        for (int j = 0; j < p[i].size(); j ++) {
            if (cal[p[i][j]]) cnt ++;
            cal[p[i][j]] = cal[to[p[i][j]][0]] = 1;
        }
        for (int j = i - 2; j <= i - 1; j ++) {
            for (int k = 0; k < p[j].size(); k ++) {
                cal[p[j][k]] = 0;
                cal[to[p[j][k]][0]] = 0;
            }
        }
        for (int j = 0; j < p[i - 3].size(); j ++) {
            ans[p[i - 3][j]] = now + cnt;
        }
        for (int j = 0; j < p[i].size(); j ++) {
            cal[p[i][j]] = cal[to[p[i][j]][0]] = 0;
            now ++;
        }
    }
    for (int i = 0; i < 2 * n; i ++) {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}

#endif

/*

*/
