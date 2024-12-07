/*
题目保证一定有解
每出现 1 次 1，一定会增加当前列表级数
出现其他数只可能是同级或者降级
1 1 2 3 2
1
1.1
1.2
1.3
2
或者
1
1.1
2
3
2（非法）
由这个例子可以看出，能同级就同级，实在同级不了再降级
如果是 a[i] = a[i - 1] + 1，则可以同级操作
否则降级，降最少的级
是否存在必须多降一点才能构造出来的列表？
*/

int n, a[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> cur;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            cur.push_back(1);
        } else {
            assert(cur.size() > 0);
            if (a[i] == cur.back() + 1) {
                cur.pop_back();
                cur.push_back(a[i]);
            } else {
                while (cur.size() > 0 && a[i] != cur.back() + 1) {
                    cur.pop_back();
                }
                if (cur.size() == 0) {
                    cur.push_back(a[i]);
                } else {
                    cur.pop_back();
                    cur.push_back(a[i]);
                }
            }
        }
        for (int j = 0; j < cur.size(); j++) {
            cout << cur[j];
            if (j != cur.size() - 1) {
                cout << ".";
            } 
        }
        cout << "\n";
    }
}
