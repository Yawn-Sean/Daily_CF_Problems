/*
矩阵是 1e5 * 1e5，非常大，且有 1e5 次询问，单次询问要做到 O(logn) 或者 O(1)
两偶和两奇相加才能得到偶数
假如现在在 (i, j) 位置，假如移动到 (i, j - 1) 或者 (i, j + 1)
则 c[j] 和 c[j - 1]/c[j + 1] 的奇偶性必须相同
所以，c 的奇偶性不能变
假如是横坐标变，则 r 的奇偶性不能变
考虑一直走下去，会发现其实 r 和 c 的奇偶性一直得和最开始一样
由于只能往相邻的地方走，所以其实给定了 (i, j) 就是看包含 r[i] 的奇偶性相同区间和包含 c[j] 的奇偶性相同区间
这两个区间做笛卡尔积得到的区域，就是 (i, j) 这个点能到的所有地方
我们把起点和终点的区域都算出来，看有没有交集即可，有交集说明能走到
*/

int T;
int n, q;

void solve1() {
    cin >> n >> q;
    vector<int> r(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
        r[i] %= 2;
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        c[i] %= 2;
    }

    vector<int> up(n + 1), down(n + 1), left(n + 1), right(n + 1);
    up[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (r[i] == r[i - 1]) {
            up[i] = up[i - 1];
        } else {
            up[i] = i;
        }
    }
    down[n] = n;
    for (int i = n - 1; i > 0; i--) {
        if (r[i] == r[i + 1]) {
            down[i] = down[i + 1];
        } else {
            down[i] = i;
        }
    }
    left[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i - 1]) {
            left[i] = left[i - 1];
        } else {
            left[i] = i;
        }
    }
    right[n] = n;
    for (int i = n - 1; i > 0; i--) {
        if (c[i] == c[i + 1]) {
            right[i] = right[i + 1];
        } else {
            right[i] = i;
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int up1 = up[x1], down1 = down[x1], left1 = left[y1], right1 = right[y1];
        int up2 = up[x2], down2 = down[x2], left2 = left[y2], right2 = right[y2];
        if ( (up1 <= up2 && up2 <= down1) || (up2 <= up1 && up1 <= down2) ) {
            if ( (left1 <= left2 && left2 <= right1) || (left2 <= left1 && left1 <= right2) ) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n";
        }
    }
}       
