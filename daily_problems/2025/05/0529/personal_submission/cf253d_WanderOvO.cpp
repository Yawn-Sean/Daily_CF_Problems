/*
四次方暴力做法，就是枚举左上和右下角的点，判断四个角是否相等，前缀和算大小
如果只枚举左上角，然后暴力枚举左下角的行号，快速求出 a 不超范围的右边的列的号
随着枚举的左下角行号的增加，右边列的号只会单调不增，所以相当于是双指针维护 a 的限制
求出对应的列号之后，不超过这个列号的列都可以考虑，下面就是看怎么满足四个角都相等的要求了

改为考虑先枚举固定矩形的左右边
根据上一个思路，可以再枚举上边，双指针维护出来下边的满足 a 限制的范围
进一步，如何满足四个角相等呢？
我们需要看在固定左右边的情况下，左右相等的行有几个，按照字符种类组织起来
现在我们还固定了上边，则上边假如相等，则看其字符是谁，在对应的字符的左右相等行里面计算个数即可
*/

string grid[M];
int n, m, k, sum[M][M];

void meibao() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        grid[i] = " " + grid[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (grid[i][j] == 'a');
        }
    }
    
    auto query = [&] (int i, int l, int j, int r) -> int {
        return sum[j][r] - sum[i - 1][r] - sum[j][l - 1] + sum[i - 1][l - 1];
    };

    LL res = 0;
    for (int l = 1; l <= m; l++) {
        for (int r = l + 1; r <= m; r++) {
            vector<vector<int>> pos(26);
            int p1[26], p2[26] = {0};
            for (int i = 0; i < 26; i++) {
                p1[i] = 1;
            }
            for (int i = 1; i <= n; i++) {
                if (grid[i][l] == grid[i][r]) {
                    pos[grid[i][l] - 'a'].push_back(i);
                }
            }

            int j = 0;
            for (int i = 1; i <= n; i++) {
                while (j + 1 <= n && query(i, l, j + 1, r) <= k) {
                    j++;
                }

                if (grid[i][l] == grid[i][r] && i + 1 <= j) {
                    int id = grid[i][l] - 'a';
                    while (p1[id] < pos[id].size() && pos[id][p1[id]] <= i) {
                        p1[id]++;
                    }
                    while (p2[id] + 1 < pos[id].size() && pos[id][p2[id] + 1] <= j) {
                        p2[id]++;
                    }
                    if (p2[id] >= p1[id]) {
                        res += p2[id] - p1[id] + 1;
                    }
                }
            }
        }
    }
    cout << res << "\n";
}
