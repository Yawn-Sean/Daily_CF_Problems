/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-04 18:59 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL x;
    cin >> x;
    vector<std::pair<LL, LL>> ans;
    for (LL n = 1; n <= 2000000; n ++) {
        LL A = (n - 1) * n * (2 * n - 1) / 6;
        LL B = n * (n - 1) / 2;
        if ((x - A + n * B) % (n * n - B) == 0 && n <= ((x - A + n * B) / (n * n - B))) {
            ans.push_back({n, ((x - A + n * B) / (n * n - B))});
            if (n != ((x - A + n * B) / (n * n - B))) ans.push_back({(x - A + n * B) / (n * n - B), n});
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return 0;
}

#endif

/*

*/
