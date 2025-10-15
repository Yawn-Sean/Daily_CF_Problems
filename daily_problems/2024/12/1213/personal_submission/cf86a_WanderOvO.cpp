/*
a + b = 9...9(cnt 个 9)
假设 a 为 cnt 位数，啥时候 a * b 最大？
基本不等式，知 a = 49...9 或者 50...0 时最大
a 从 10...0 到 50...0 单调不减，从 50...1 到 99...9 单调递减
*/

LL l, r;

int get_count(LL x) {
    if (x == 0) {
        return 1;
    }
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

void meibao() {
    cin >> l >> r;
    int cnt1 = get_count(l), cnt2 = get_count(r);
    if (cnt1 < cnt2) {
        LL mx = 1;
        for (int i = 1; i <= cnt2; i++) {
            mx *= 10;
        }
        mx /= 2;
        if (r >= mx - 1) {
            cout << mx * (mx - 1) << "\n";
        } else {
            cout << r * (mx * 2 - 1 - r) << "\n";
        }
    } else {
        LL mx = 1;
        for (int i = 1; i <= cnt2; i++) {
            mx *= 10;
        }
        mx /= 2;
        if (mx - 1 >= l && mx - 1 <= r) {
            cout << mx * (mx - 1) << "\n";
        } else {
            if (r <= mx - 1) {
                cout << r * (mx * 2 - 1 - r) << "\n";
            } else {
                cout << l * (mx * 2 - 1 - l) << "\n";
            }
        }
    }
}
