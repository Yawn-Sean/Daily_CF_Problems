/*
输入保证给的一定是不好的序列
输入中至少有一对的大小关系是不符合要求的，所以这对的这两个数一定有一个要被用来交换，也可能二者互换
所以我们只需要枚举这两个数中的某个，再从其他数里面枚举另一个要被交换的数，然后看交换之后行不行即可
如何快速检查交换之后行不行？
我们可以把所有不满足 a[i] 和 a[i + 1] 大小关系的 i 存起来
交换一次，至多影响 4 对的大小关系，其他的应该本来就是满足要求的
所以，假如有 5 对或更多不满足条件的，怎么换都不行
4 对或者更少的情况，暴力看是不是变得符合了即可，先看不合法的那些是否合法了，再看改变的那几个是否还合法
*/

int n, a[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> invalid;
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            if (a[i] <= a[i + 1]) {
                invalid.push_back(i);
            }
        } else {
            if (a[i] >= a[i + 1]) {
                invalid.push_back(i);
            }
        }
    }

    if (invalid.size() > 4) {
        cout << "0\n";
    } else {
        int res = 0;
        assert(invalid.size() > 0);
        int p1 = invalid[0], p2 = invalid[0] + 1;

        auto unit_check = [&] (int p) -> bool {
            if (p >= n || p <= 0) {
                return true;
            }
            bool ok = true;
            if (p % 2 == 0) {
                if (a[p] <= a[p + 1]) {
                    ok = false;
                }
            } else {
                if (a[p] >= a[p + 1]) {
                    ok = false;
                }
            }
            return ok;
        };

        auto check = [&] (int pos1, int pos2) -> bool {
            bool ok = true;
            for (auto p : invalid) {
                ok &= unit_check(p);
                ok &= unit_check(p - 1);
                ok &= unit_check(p + 1);
            }
            ok &= unit_check(pos1);
            ok &= unit_check(pos2);
            ok &= unit_check(pos1 + 1);
            ok &= unit_check(pos1 - 1);
            ok &= unit_check(pos2 + 1);
            ok &= unit_check(pos2 - 1);
            return ok;
        };

        for (int i = 1; i <= n; i++) {
            if (i != p1 && i != p2) {
                swap(a[p1], a[i]);
                if (check(p1, i)) {
                    res++;
                }
                swap(a[p1], a[i]);

                swap(a[p2], a[i]);
                if (check(p2, i)) {
                    res++;
                }
                swap(a[p2], a[i]);
            }
        }

        swap(a[p1], a[p2]);
        if (check(p1, p2)) {
            res++;
        }
        swap(a[p1], a[p2]);
        cout << res << "\n";
    }
}  
