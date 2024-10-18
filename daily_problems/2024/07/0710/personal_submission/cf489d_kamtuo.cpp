/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-10 11:22 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 3234, M = 31234;

int n, m;
vector<int> lo[N];
vector<std::pair<int, int>> now;
int mp[N][N];
LL p[M];
LL ans;

LL C(int n, int m) {
    return 1ll * n * (n - 1) / 2ll;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        now.push_back({x, y});
        lo[y].push_back(x);
    }
    for (int i = 0; i < now.size(); i ++) {
        int x = now[i].first, y = now[i].second;
        for (int j = 0; j < lo[x].size(); j ++) {
            mp[lo[x][j]][y] ++;
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (mp[i][j] >= 2 && i != j) ans += C(mp[i][j], 2);
        }
    }
    cout << ans << endl;
    return 0;
}

/*

*/
