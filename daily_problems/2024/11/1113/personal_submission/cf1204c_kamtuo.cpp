/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-13 19:09 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string> mp(n);
    vector dist(n, vector (n, 0x3f3f3f3f));
    for (int i = 0; i < n; i ++) {
        cin >> mp[i];
        dist[i][i] = 0;
        for (int j = 0; j < n; j ++) {
            if (mp[i][j] == '1') dist[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            for (int k = 0; k < n; k ++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    int m;
    cin >> m;
    vector to(m, 0);
    for (int i = 0; i < m; i ++) {
        cin >> to[i];
        to[i] --;
    }
    vector<int> ans; 
    ans.push_back(to[0]);
    int now = 0, nex;
    while (now < m - 1) {
        nex = now;
        while (nex < m - 1 && dist[to[now]][to[nex + 1]] == dist[to[now]][to[nex]] + 1) nex ++;
        ans.push_back(to[nex]);
        now = nex;
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i ++) cout << ans[i] + 1 << " ";
    return 0;
}

#endif

/*

*/
