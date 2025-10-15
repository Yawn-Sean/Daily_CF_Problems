/*
a[j] > 0
i > a[j]^(1 / 3) + j
i < -a[j]^(1 / 3) + j
相当于维护有序的 a[j]^(1 / 3) + j 和 -a[j]^(1 / 3) + j
a[j]^(1 / 3) + j 要向上取整，-a[j]^(1 / 3) + j 要向下取整，注意恰好为立方数的情况
每次看最小的 a[j]^(1 / 3) + j 和最大的 -a[j]^(1 / 3) + j，看看是否可行即可
修改操作怎么搞？
记录每个位置是什么数
使用两个 set，分别记录 {a[j]^(1 / 3) + j, j} 和 {-a[j]^(1 / 3) + j, j}
只查最大最小的就好了
*/

LL n, a[N], q;
set<PLL> s1, s2;

// flag = 0, 返回比立方根严格更小的一个整数，flag = 1，返回比立方根严格更大的一个整数
LL get_root(LL val, int flag) {
    LL l = 0, r = 1e3, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (mid * mid * mid <= val) {
            l = mid;
        } else {
            r = mid;
        }
    }

    LL res;
    if (r * r * r <= val) {
        res = r;
    } else {
        res = l;
    }

    if (flag == 0) {
        if (res * res * res == val) {
            return res - 1;
        } else {
            return res;
        }
    } else {
        return res + 1;
    }
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        LL r2 = get_root(a[i], 1);
        s1.insert({r2 + i, i});
        s2.insert({-r2 + i, i});
    }
    
    cin >> q;
    while (q--) {
        LL op, pos, val;
        cin >> op;
        if (op == 1) {
            cin >> pos >> val;
            LL old_r = get_root(a[pos], 1);
            s1.erase({old_r + pos, pos});
            s2.erase({-old_r + pos, pos});

            a[pos] = val;
            LL new_r = get_root(val, 1);
            s1.insert({new_r + pos, pos});
            s2.insert({-new_r + pos, pos});
        } else {
            cin >> pos;
            auto it1 = *s1.begin(), it2 = *prev(s2.end());
            if (it1.first <= pos) {
                cout << it1.second << "\n";
            } else if (it2.first >= pos) {
                cout << it2.second << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }
}   
