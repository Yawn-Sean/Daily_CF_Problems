/*
考虑钦定一下矩形的纵坐标范围，然后看这个范围内有多少行都是 1
我们把同一行连续的 1 当成一个线段，自己枚举的纵坐标范围也是个线段
则想看多少个线段完全包含自己枚举的这个线段
左端点 <= 自己枚举的左端点的情况下，有多少线段右端点 >= 自己枚举的右端点
所有线段按照左端点排序，相当于看前缀里有多少 >= 某个数的右端点
使用树状数组维护即可
*/

BIT bit;
int n, m, idx;
string grid[M];
PII segs[N];

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        grid[i] = " " + grid[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; ) {
            if (grid[i][j] == '1') {
                int k = j;
                while (k <= m && grid[i][j] == grid[i][k]) {
                    k++;
                }
                segs[++idx] = {j, k - 1};
                j = k;
            } else {
                j++;
            }
        }
    }

    sort(segs + 1, segs + idx + 1);
    
    bit.init(M);

    int cur = 1;
    int res = 0;
    for (int i = 1; i <= m; i++) {
        while (cur <= idx && segs[cur].x <= i) {
            bit.add(segs[cur].y, 1);
            cur++;
        }
        for (int j = i; j <= m; j++) {
            int cnt = (cur - 1) - bit.query(j - 1);
            res = max(res, cnt * (j - i + 1));
        }
    }
    cout << res << "\n";
}  
