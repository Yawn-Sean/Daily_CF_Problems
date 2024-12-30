/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-05 17:31 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 312345, M = 612;

LL dp[M][M];
int pos[N];
LL a[N];
int n;
LL ans[N];
vector<std::pair<int, int>> ab[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    } 
    int q;
    cin >> q;
    for (int i = 1; i <= q; i ++) {
        int x, y;
        cin >> x >> y;
        if (y <= 600) ab[x].push_back({y, i});
        else {
            for (int j = x; j <= n; j += y) ans[i] += a[j];
        }
    }
    for (int i = n; i >= 1; i --) {
        pos[i] = (600 - (n - i + 1)) % 600 + 600;
        pos[i] %= 600; 
        for (int j = 1; j <= 600; j ++) {
            dp[pos[i]][j] = dp[pos[i + j]][j] + a[i];
        }
        for (int j = 0; j < ab[i].size(); j ++) {
            ans[ab[i][j].second] = dp[pos[i]][ab[i][j].first];
        }
    }
    for (int i = 1; i <= q; i ++) {
        cout << ans[i] << "\n";
    }
    // for (int i = 1; i <= n; i ++) cout << pos[i] << " \n"[i == n];
    return 0;
}

/*

*/
