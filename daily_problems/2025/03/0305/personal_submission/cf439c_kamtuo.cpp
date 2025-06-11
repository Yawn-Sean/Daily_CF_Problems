/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2025-03-05 13:33                         */
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
    int n, k, p;
    cin >> n >> k >> p;
    vector a(n + 1, 0);
    vector<int> odd, even;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i]; 
        if (a[i] % 2) odd.push_back(a[i]); 
        else even.push_back(a[i]);
    }
    if (odd.size() >= k - p) {
        if ((odd.size() - k + p) % 2 == 0 && (odd.size() - k + p) / 2 + even.size() >= p) {
            cout << "YES\n";
            vector ans(k, vector<int> ());
            for (int i = 0; i < k - p; i ++) ans[i].push_back(odd.back()), odd.pop_back();
            for (int i = k - p; i < k; i ++) {
                if (even.size()) {
                    ans[i].push_back(even.back());
                    even.pop_back();
                } else {
                    ans[i].push_back(odd.back());
                    odd.pop_back();
                    ans[i].push_back(odd.back());
                    odd.pop_back();
                }
            }
            while (even.size()) {
                ans[0].push_back(even.back());
                even.pop_back();
            }
            while (odd.size()) {
                ans[0].push_back(odd.back());
                odd.pop_back();
                ans[0].push_back(odd.back());
                odd.pop_back();
            }
            for (int i = 0; i < k; i ++) {
                cout << ans[i].size() << " ";
                for (int j = 0; j < ans[i].size(); j ++) cout << ans[i][j] << " ";
                cout << "\n";
            }
            return 0;
        } 
    }
    cout << "NO\n";
    return 0;
}

#endif

/*

*/
