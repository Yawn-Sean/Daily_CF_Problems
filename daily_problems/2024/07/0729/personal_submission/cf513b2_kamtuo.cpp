/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-29 19:10 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

LL n, m;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    int l = 0, r = n - 1;
    LL now = 0;
    vector<int> ans(n);
    for (int i = 1; i <= n; i ++) {
        if ((1ll << (n - i - 1)) + now >= m) {
            ans[l ++] = i;
        } else {
            now += 1ll << (n - i - 1);
            ans[r --] = i; 
        }
    }
    for (int i = 0; i < ans.size(); i ++) cout << ans[i] << ' ';
    return 0;
}


/*

*/


