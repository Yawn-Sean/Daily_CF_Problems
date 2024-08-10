/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-14 15:26 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 123;

char mp[N][N];
int n, m;
int idx[] = {0, 0, 1, -1}, idy[] = {1, -1, 0, 0};

bool isletter(char ch, char now) {
    return (ch == now);
}

bool draw(int x, int y, char ch) {
    queue<std::pair<int, int>> q;
    vector<vector<bool>> st(N, vector<bool>(N, false));
    q.push({x, y});
    st[x][y] = true;
    int left = y, right = y, up = x, down = x;
    while (!q.empty()) {
        std::pair<int, int> now = q.front();
        left = min(left, now.second);
        right = max(right, now.second);
        up = min(up, now.first);
        down = max(down, now.first);
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int nowx = now.first + idx[i], nowy = now.second + idy[i];
            if (isletter(mp[nowx][nowy], ch)) {
                if (st[nowx][nowy] == false) {
                    st[nowx][nowy] = true;
                    q.push({nowx, nowy});
                }
            }
        }
    }
    int len = max(right - left + 1, down - up + 1);
    for (int i = up; i <= up + len - 1; i ++) {
        for (int j = left; j <= left + len - 1; j ++) {
            if (i > n || j > m || i < 1 || j < 1) return false;
            if (mp[i][j] != ch && mp[i][j] != '*') return false;
        }
    }
    for (int i = up; i <= up + len - 1; i ++) {
        for (int j = left; j <= left + len - 1; j ++) {
            mp[i][j] = ch;
        }
    }
    return true;
}



int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            mp[i][j] = '*';
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (mp[i][j] == '*') {
                for (char k = 'A'; k <= 'Z'; k ++) {
                    if (draw(i, j, k)) break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << mp[i][j];
        }
        cout << endl;
    }
    return 0;
}

/*

*/
