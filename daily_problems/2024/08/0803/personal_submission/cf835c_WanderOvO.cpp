/*
维护二维前缀和
注意到最大亮度只有 10，感觉可以相对暴力地做
s[light][i][j] 表示初始亮度为 light，从 (1, 1) 到 (i, j) 的星星个数
询问 (x1, y1) 到 (x2, y2) 区域时，可以按照初始亮度分类求和
假设初始亮度为 light 的星星在该区域内有 cnt 个，则和为 ((light + t) % (c + 1)) * cnt
*/

int T; 
int s[M][N][N];

void solve1() {
    int n, q, c;
    cin >> n >> q >> c;
    for (int i = 1; i <= n; i++) {
        int x, y, light;
        cin >> x >> y >> light;
        s[light][x][y]++;
    }
    for (int light = 0; light <= c; light++) {
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < N; j++) {
                s[light][i][j] += s[light][i - 1][j] + s[light][i][j - 1] - s[light][i - 1][j - 1];
            }
        }
    }

    while (q--) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int res = 0;
        for (int light = 0; light <= c; light++) {
            int cnt = s[light][x2][y2] - s[light][x1 - 1][y2] - s[light][x2][y1 - 1] + s[light][x1 - 1][y1 - 1];
            res += ((light + t) % (c + 1)) * cnt;
        }
        cout << res << "\n";
    }
}   
