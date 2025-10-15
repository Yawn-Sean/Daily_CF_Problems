/*
对于 a, b, c <= 3 的情况，似乎可以暴力枚举
所有 a 的长度一样，所以字典序大小其实就是数值大小，从小到大枚举即可
对于某个 a 的 val，可以算出来有多少个 b 符合题意
b 最小是 10^(b - 1)，最大是 min(10^b - 1, 10^c - 1 - val)
倘若 b 的 max < min，就说明这个 val 太大了，无需再看
大部分是 a, b, c <= 3，所以大部分用例需要 1000 次的枚举才能求出来
个别用例很大，单个需要 1e6 左右
*/

LL a, b, c, k;

void meibao() {
    cin >> a >> b >> c >> k;
    int min_a = 1, max_a = 1;
    for (int i = 1; i < a; i++) {
        min_a *= 10;
    }
    for (int i = 1; i <= a; i++) {
        max_a *= 10;
    }
    max_a--;

    int max_c = 1;
    for (int i = 1; i <= c; i++) {
        max_c *= 10;
    }
    max_c--;
    int min_c = 1;
    for (int i = 1; i < c; i++) {
        min_c *= 10;
    }

    int min_b = 1;
    for (int i = 1; i < b; i++) {
        min_b *= 10;
    }
    int max_b = 1;
    for (int i = 1; i <= b; i++) {
        max_b *= 10;
    }
    max_b--;

    LL cnt = 0;
    for (int val_a = min_a; val_a <= max_a; val_a++) {
        int cur_max_b = min(max_b, max_c - val_a);
        int cur_min_b = max(min_b, min_c - val_a);
        if (cur_max_b < cur_min_b) {
            continue;
        }

        LL c = cur_max_b - cur_min_b + 1;
        if (cnt + c < k) {
            cnt += c;
        } else {
            LL step = k - cnt;
            cout << val_a << " + " << cur_min_b + step - 1 << " = " << val_a + cur_min_b + step - 1 << "\n";
            return;
        }
    }

    if (cnt < k) {
        cout << "-1\n";
        return;
    }
}   
