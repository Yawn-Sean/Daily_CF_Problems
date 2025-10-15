/*
显然至多增加两个点就可以，下面只需要分类讨论到底加几个点
枚举每个现有的点的坐标 a[i]，看 a[i] + x/y 和 a[i] - x/y 是否存在
假如把 x 和 y 的差距都找到了，则为 0
否则，考虑增加点
- 如果 x 和 y 中恰好有一个差距找不到，则随便从 0 开始数一段长度标记上即可
- 如果 x 和 y 都找不到，则可能需要加 1-2 个点
  - 枚举每个现有的点，计算 a[i] + x 和 a[i] - x，存起来，注意越界
  - 同样存 a[i] + y 和 a[i] - y，但是用另一个集合
  - 两个集合有交集，说明加一个点就够了
  - 两个集合没有交集，则直接加 x 和 y 即可
*/
 
int n, l, x, y;
int a[N];
 
void meibao() {
    cin >> n >> l >> x >> y;
    set<int> s1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s1.insert(a[i]);
    }
    bool has_x = false, has_y = false;
    for (int i = 1; i <= n; i++) {
        if (s1.count(a[i] + x) || s1.count(a[i] - x)) {
            has_x = true;
        }
        if (s1.count(a[i] + y) || s1.count(a[i] - y)) {
            has_y = true;
        }
    }
    if (has_x && has_y) {
        cout << "0\n";
    } else if (has_x) {
        cout << "1\n" << y << "\n";
    } else if (has_y) {
        cout << "1\n" << x << "\n";
    } else {
        set<int> s2;
        for (int i = 1; i <= n; i++) {
            if (a[i] + x <= l && a[i] + x >= 0) {
                s2.insert(a[i] + x);
            }
            if (a[i] - x >= 0 && a[i] - x <= l) {
                s2.insert(a[i] - x);
            }
        }
        bool both = false;
        int p = -1;
        for (int i = 1; i <= n && !both; i++) {
            if (s2.count(a[i] + y)) {
                p = a[i] + y;
                both = true;
            } else if (s2.count(a[i] - y)) {
                p = a[i] - y;
                both = true;
            }
        }
        if (both) {
            cout << "1\n";
            cout << p << "\n";
        } else {
            cout << "2\n";
            cout << x << " " << y << "\n";
        }
    }
}
