/*
(x, y) -> (x, x + y) 或者 (x + y, y)，最少次数让较大的那个数 >= m
(1, 3) -> (1, 4) -> (1, 5) -> (1, 6)
(1, 3) -> (4, 3) -> (4, 7) -> (11, 7)
贪心地让小的数加上大的数，则可以越增加越快
(1, 1) -> (1, 2) -> (3, 2) -> (3, 5) -> (8, 5) -> (8, 13)
类似斐波那契数列，至少是指数级别的增长速度，所以应该很快就能到达目标
负数的影响？分类讨论：
- m > 0
  - max(x, y) <= 0，无解
  - max(x, y) > 0，如果 max(x, y) >= m，则直接就可以了
    否则先把较小的那个加成正数，然后再轮换加0
- m = 0
  - max(x, y) >= 0，可以
  - max(x, y) < 0，寄了
- m < 0
  - max(x, y) >= m，可以
  - max(x, y) < m，不可能更大了，寄了
*/
 
int T;
LL x, y, m;
 
void solve1() {
    cin >> x >> y >> m;
    if (m <= 0) {
        if (max(x, y) >= m) {
            cout << "0\n";
        } else {
            cout << "-1\n";
        }
    } else {
        if (max(x, y) <= 0) {
            cout << "-1\n";
        } else {
            if (x < y) {
                swap(x, y);
            }
            if (x >= m) {
                cout << "0\n";
            } else {
                LL res = 0;
                if (y < 0) {
                    res += ((-y + x - 1) / x);
                    LL r = (-y) % x;
                    y = (x - r) % x;
                }
                while (max(x, y) < m) {
                    if (x < y) {
                        swap(x, y);
                    }
                    y += x;
                    res++;
                }
                cout << res << "\n";
            }
        }
    }
}  
