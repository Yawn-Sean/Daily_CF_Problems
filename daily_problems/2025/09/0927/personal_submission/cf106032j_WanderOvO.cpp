/*
如果每个数出现次数都是奇数次，则无法进行移位，直接回答即可
本来是偶数次的，在移位时一定会遇到奇数次的数，并与之合并，之后就不动了
其他数也不可能解救这个数了，因为能移位的其他数一定是出现偶数次的
所以 s 集合随着移位的进行，大小是单调不增的
如果所有数都是好的，则移位一直能进行下去
但凡有一个不好的数，在进行 M - 1 次操作之后，所有的数一定都变得不好了
我们可以预先知道，每种好数至多可以移位多少次，换句话说，移位到值为多少时会停止
在移位次数没到这个上限时，我们根据移位次数输出结果
到了之后，只能输出终止时的那个结果
这样就无需真正进行移位操作了
*/

int cnt[N], n, m, q, a[N], max_can_arrive[N];

void meibao() {
    cin >> n >> m >> q;

    for (int i = 0; i <= m; i++) {
        cnt[i] = 0;
        max_can_arrive[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    bool has_odd = false;
    for (int i = 1; i <= m; i++) {
        if (cnt[i] % 2) {
            has_odd = true;
        }
    }

    if (!has_odd) {
        int shift_cnt = 0;
        while (q--) {
            int op;
            cin >> op;
            if (op == 1) {
                shift_cnt++;
            } else {
                int pos;
                cin >> pos;
                cout << ((a[pos] - 1 + shift_cnt) % m + m) % m + 1 << "\n";
            }
        }
    } else {
        int pt = 1;
        for (int i = 1; i <= m; i++) {
            if (cnt[i] > 0) {
                if (cnt[i] % 2) {
                    max_can_arrive[i] = i;
                    pt = i;
                } else {
                    while (pt <= i || cnt[(pt - 1) % m + 1] % 2 == 0) {
                        pt++;
                    }
                    max_can_arrive[i] = (pt - 1) % m + 1;
                }
            }
        }

        int shift_cnt = 0;
        while (q--) {
            int op;
            cin >> op;
            if (op == 1) {
                shift_cnt++;
            } else {
                int pos;
                cin >> pos;
                int val = a[pos];
                int cnt = 0;
                if (max_can_arrive[val] >= val) {
                    cnt = max_can_arrive[val] - val;
                } else {
                    cnt = m - val + max_can_arrive[val];
                }

                if (shift_cnt <= cnt) {
                    cout << ((a[pos] - 1 + shift_cnt) % m + m) % m + 1 << "\n";
                } else {
                    cout << max_can_arrive[val] << "\n";
                }
            }
        }
    }
}   
