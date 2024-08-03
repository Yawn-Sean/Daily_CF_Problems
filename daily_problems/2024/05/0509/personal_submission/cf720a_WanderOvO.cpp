/*
尽量越近越好，密集队形，1 的区域和 2 的区域应该是互不包含的
从 (0, 0) 和 (0, m + 1) 进来，格子坐标是从 (1, 1) 到 (n, m)，所以最小是 2
有 1 个 2，2 个 3，... min(n, m) 个 min(n, m) + 1，min(n, m) 个 min(n, m) + 2..
左上区域最好让 1 填，因为 1 离得更近
先枚举第一组中的点（按照体力单调不减的顺序）
对于每个点，遍历矩阵，找到符合体力要求且离 2 尽可能远的位置
*/

int T;
int n, m;

void solve1() {
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
    vector<int> a, b;
    int cnt1, cnt2;
    cin >> cnt1;
    for (int i = 1; i <= cnt1; i++) {
        int val;
        cin >> val;
        a.pb(val);
    }
    cin >> cnt2;
    for (int i = 1; i <= cnt2; i++) {
        int val;
        cin >> val;
        b.pb(val);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for (auto val : a) {
        int posx = 0, posy = 0, dist1 = n + m, dist2 = 0; 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i + j > val) {
                    break;
                }
                if (grid[i][j] != 0) {
                    continue;
                }
                
                if (i + (m + 1 - j) >= dist2) {
                    posx = i;
                    posy = j;
                    dist2 = i + (m + 1 - j);
                    dist1 = i + j;
                }
            }
        }
        if (posx == 0 && posy == 0) {
            cout << "NO\n";
            return;
        }
        
        grid[posx][posy] = 1;
    }
    int cnt = 0;
    for (auto val : b) {
        cnt++;
        int posx = 0, posy = 0, dist2 = n + m; 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i + (m + 1 - j) > val) {
                    continue;
                }
                if (grid[i][j] != 0) {
                    continue;
                }
                
                if (i + (m + 1 - j) <= dist2) {
                    posx = i;
                    posy = j;
                    dist2 = i + (m + 1 - j);
                }
            }
        }
        if (posx == 0 && posy == 0) {
            cout << "NO\n";
            return;
        }
        if (dist2 > val) {
            cout << "NO\n";
            return;
        }
        
        grid[posx][posy] = 2;
    }
    cout << "YES\n";
}     