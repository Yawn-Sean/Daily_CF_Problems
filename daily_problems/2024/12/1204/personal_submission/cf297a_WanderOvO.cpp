/*
a 串最终能变成什么？
a 的一个后缀 + 若干 parity 得到的结果
数据范围很小，只有 1000
a 的那个后缀必须等于 b 的前缀，所以不是前缀的话就得删了
假设 a 最开始包含 cnt 个 1，如果 cnt 为奇数，则变换完至多有 cnt + 1 个 1，否则至多有 cnt 个 1
枚举所有的满足 a 的后缀是 b 的前缀的后缀，然后考虑剩下的部分能不能拼出来
拼连续的 0 很简单，但是拼 1 比较难
拼第一个 1，需要前面的 1 是奇数个，拼完总共就成了偶数个 1
拼第二个 1，需要删除掉前面的 1 个 1，才能往后拼
以后的 1，都得删掉一个前面的，才能往后面放
*/

string a, b;
MyHash ha, hb;

void meibao() {
    cin >> a >> b;
    ha.init(a, P, MOD1);
    hb.init(b, P, MOD1);
    int n = a.size(), m = b.size();
    for (int i = n; i >= 0 && n - i <= m; i--) {
        if (i == n || (ha.get(i, n - 1) == hb.get(0, n - i - 1))) {
            int cnt1 = 0, sufcnt1 = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] == '1') {
                    cnt1++;
                    if (j >= i) {
                        sufcnt1++;
                    }
                }
            }

            int need_cnt1 = 0;
            for (int j = n - i; j < m; j++) {
                if (b[j] == '1') {
                    need_cnt1++;
                }
            }

            int supply_cnt1 = cnt1 - sufcnt1;
            if (cnt1 % 2 != 0) {
                supply_cnt1++;
            }
            if (supply_cnt1 < need_cnt1) {
                continue;
            }
            if (need_cnt1 == 0) {
                if (sufcnt1 % 2 != 0) {
                    continue;
                }
            } 
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}
