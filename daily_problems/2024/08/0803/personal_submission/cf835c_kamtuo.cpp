/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-03 09:36 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 212;

#if !KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q, c;
    cin >> n >> q >> c;
    c ++;
    vector x(n + 1, 0), y(n + 1, 0);
    vector tot(c, vector(N, vector(N, 0)));
    std::function<int(int, int)> mod = [&] (int a, int m) -> int {
        return (a % m + m) % m; 
    };
    for (int i = 1; i <= n; i ++) {
        int w;
        cin >> x[i] >> y[i] >> w;
        for (int j = 0; j < c; j ++) tot[j][x[i]][y[i]] += (w + j) % c;
    }
    for (int to = 0; to < c; to ++) {
        for (int i = 1; i < N; i ++) {
            for (int j = 1; j < N; j ++) {
                tot[to][i][j] = tot[to][i][j] + tot[to][i - 1][j] + tot[to][i][j - 1] - tot[to][i - 1][j - 1];
            }
        }
    }
    for (int i = 1; i <= q; i ++) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        // x2 --, y2 --;
        t %= c;
        int nt = tot[t][x2][y2] + tot[t][x1 - 1][y1 - 1] - tot[t][x2][y1 - 1] - tot[t][x1 - 1][y2];
        cout << nt << endl;
    }
    return 0;
}

#endif

/*

*/
