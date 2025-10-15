/*
交换 a[x], a[y] 变成交换转换后数组的 b[a[x]], b[a[y]]
1 4 2 3 5
5 4 3 2 1
如何计算转换后的数组的区间 [x, y] 的剃头次数？
其实就是求怎么把 [x, y] 区间切分成最少的上升子数组，注意是子数组
假如 b[i] > b[i + 1]，则在 i 位置标记 1
[x, y] 的最少上升子数组数就是 [x, y - 1] 的标记数，区间求和

接下来考虑交换，p1 = a[x], p2 = a[y]
p1 和 p2 相邻，单独处理，至多影响 p1 - 1, p1, p1 + 1
p1 和 p2 不相邻，至多影响 4 个位置的标记，4 次单点修改
*/

BIT tr;
int n, q, a[N], b[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        b[a[i]] = i;
    }

    /*
    cout << "b: ";
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
    */

    tr.init(n);
    for (int i = 1; i < n; i++) {
        if (b[i] > b[i + 1]) {
            tr.add(i, 1);
        }
    }

    cin >> q;
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            cout << tr.query(y - 1) - tr.query(x - 1) + 1 << "\n";
        } else {
            int p1 = a[x], p2 = a[y];
            int val1 = a[x], val2 = a[y];
            swap(a[x], a[y]);
            if (p1 > p2) {
                swap(p1, p2);
                swap(val1, val2);
            }

            if (p2 == p1 + 1) {
                // 只影响 p1 - 1, p1, p1 + 1
                if (p2 != n && b[p2] > b[p2 + 1] && b[p1] < b[p2 + 1]) {
                    tr.add(p2, -1);
                } else if (p2 != n && b[p2] < b[p2 + 1] && b[p1] > b[p2 + 1]) {
                    tr.add(p2, 1);
                }

                if (b[p1] > b[p2]) {
                    tr.add(p1, -1);
                } else {
                    tr.add(p1, 1);
                }

                if (p1 - 1 > 0 && b[p1 - 1] > b[p1] && b[p1 - 1] < b[p2]) {
                    tr.add(p1 - 1, -1);
                } else if (p1 - 1 > 0 && b[p1 - 1] < b[p1] && b[p1 - 1] > b[p2]) {
                    tr.add(p1 - 1, 1);
                }
            } else {
                // 影响 p1 - 1, p1, p2 - 1, p2
                if (p2 != n && b[p2] > b[p2 + 1] && b[p1] < b[p2 + 1]) {
                    tr.add(p2, -1);
                } else if (p2 != n && b[p2] < b[p2 + 1] && b[p1] > b[p2 + 1]) {
                    tr.add(p2, 1);
                }

                assert(p2 - 1 > 0);
                if (b[p2 - 1] > b[p2] && b[p2 - 1] < b[p1]) {
                    tr.add(p2 - 1, -1);
                } else if (b[p2 - 1] < b[p2] && b[p2 - 1] > b[p1]) {
                    tr.add(p2 - 1, 1);
                }

                assert(p1 + 1 <= n);
                if (b[p1] > b[p1 + 1] && b[p2] < b[p1 + 1]) {
                    tr.add(p1, -1);
                } else if (b[p1] < b[p1 + 1] && b[p2] > b[p1 + 1]) {
                    tr.add(p1, 1);
                }

                if (p1 - 1 > 0 && b[p1 - 1] > b[p1] && b[p1 - 1] < b[p2]) {
                    tr.add(p1 - 1, -1);
                } else if (p1 - 1 > 0 && b[p1 - 1] < b[p1] && b[p1 - 1] > b[p2]) {
                    tr.add(p1 - 1, 1);
                }
            }

            swap(b[p1], b[p2]);
        }
    }
}
