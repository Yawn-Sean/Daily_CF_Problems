/*
假设 abs(x) + abs(y) > n，则一定走不到，以下只讨论 abs(x) + abs(y) <= n 的情况
首先根据 x, y，能知道总体走了多少，需要至少保留的 LRUD 的数量就可以知道了
剩下的 n - abs(x) - abs(y) 次操作，需要走的总和为 0
修改长度只看最左最右的位置，中间改了多少并不管
暴力：枚举修改的最左最右位置，记为 [l, r]
算一下 < l 和 > r 的部分能走到哪个坐标，进而算出来还得横纵坐标走多少
然后对于中间的部分，先看个数上够不够改出来必须需要的，再看剩余操作是不是 2 的倍数
如何减少枚举量？
考虑枚举每个左端点，然后想办法快速计算右端点在哪里
右端点是否有单调性？
假如修改段的右端点 <= r 的时候可以，则 <= r + 1 的时候也肯定可以，所以有单调性
如何 check <= r 的时候是否可以？先看必要的够不够，再看剩下的奇偶性对不对
羊神：事实上最开始我们就可以判断奇偶性是否符合题意，n 和 abs(x) + abs(y) 的奇偶性必须相同才行
所以我们一开始就知道是否有解，后面可以放心二分
*/

int n, x, y;
string s;
int pre_x[N], pre_y[N];

bool check(int l, int r) {
    int dx = pre_x[l - 1], dy = pre_y[l - 1];
    dx += pre_x[n] - pre_x[r];
    dy += pre_y[n] - pre_y[r];
    int need_x = abs(dx - x), need_y = abs(dy - y);
    return need_x + need_y <= r - l + 1;
}

void solve1() {
    cin >> n >> s >> x >> y;
    int d = (x > 0 ? x : -x) + (y > 0 ? y : -y);
    if (d % 2 != n % 2 || d > n) {
        cout << "-1\n";
        return;
    }
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        pre_x[i] = pre_x[i - 1];
        pre_y[i] = pre_y[i - 1];
        if (s[i] == 'U') {
            pre_y[i]++;
        } else if (s[i] == 'D') {
            pre_y[i]--;
        } else if (s[i] == 'L') {
            pre_x[i]--;
        } else {
            pre_x[i]++;
        }
    }
    int res = n + 1;
    if (pre_x[n] == x && pre_y[n] == y) {
        res = 0;
    }
    for (int i = 1; i <= n; i++) {
        int l = i, r = n, mid;
        while (l + 1 < r) {
            mid = l + (r - l) / 2;
            if (check(i, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (check(i, l)) {
            res = min(res, l - i + 1);
        } else if (check(i, r)){
            res = min(res, r - i + 1);
        }
    }

    if (res == n + 1) {
        res = -1;
    }
    cout << res << "\n";
}           
