/*
如果 n <= m，一定有解，最差就是都换一遍
如果 n > m，不一定有解
不妨假设 a 中奇数目前更多，则需要把奇数换成偶数，并且还得保证奇数和偶数都没有重复数字
不妨先考虑偶数，把 a 中出现不止一次的偶数，换成 [1, m] 中的没用过的且不在 a 中的偶数
然后看 a 中的奇数，优先看出现次数 > 1 的奇数，将其换成 [1, m] 中的没用过的且不在 a 中的偶数，直到奇数偶数个数相等
最后再看 a 中的奇数，看那些出现次数 > 1 的奇数，将其换成 [1, m] 中的没用过的且不在 a 中的奇数
上面提到的找奇数/偶数需要遍历，但是显然遍历次数不会超过 2 * n，复杂度有保证
*/

int n, m, a[N];

void meibao() {
    cin >> n >> m;
    int c[3] = {0};
    map<int, int> cnt[3];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i] % 2][a[i]]++;
        c[a[i] % 2]++;
    }

    int res = 0;

    auto my_unique = [&] (int parity) -> bool {
        int idx = (parity == 0 ? 2 : 1);
        for (int i = 1; i <= n; i++) {
            if (a[i] % 2 == parity && cnt[parity][a[i]] > 1) {
                cnt[parity][a[i]]--;
                bool ok = false;
                while (idx <= m) {
                    if (!cnt[parity].count(idx)) {
                        a[i] = idx;
                        res++;
                        idx += 2;
                        ok = true;
                        break;
                    } else {
                        idx += 2;
                    }
                }
                if (!ok) {
                    return false;
                }
            }
        }

        cnt[parity].clear();
        for (int i = 1; i <= n; i++) {
            if (a[i] % 2 == parity) {
                cnt[parity][a[i]]++;
            }
        }
        return true;
    };

    // more 意味着数量多的奇偶性
    auto change = [&] (int more) -> bool {
        int idx = (more == 0 ? 1 : 2);
        assert(c[more] > c[1 - more]);
        // 先用多的那种的重复的换
        for (int i = 1; i <= n && c[more] > c[1 - more]; i++) {
            if (a[i] % 2 == more && cnt[more][a[i]] > 1) {
                cnt[more][a[i]]--;
                bool ok = false;
                while (idx <= m) {
                    if (!cnt[1 - more].count(idx)) {
                        res++;
                        a[i] = idx;
                        c[more]--;
                        c[1 - more]++;
                        idx += 2;
                        ok = true;
                        break;
                    } else {
                        idx += 2;
                    }
                }
                if (!ok) {
                    return false;
                }
            }
        }

        // 如果还不够，就用单独的再去换
        if (c[more] > c[1 - more]) {
            for (int i = 1; i <= n && c[more] > c[1 - more]; i++) {
                if (a[i] % 2 == more && cnt[more][a[i]] > 0) {
                    bool ok = false;
                    while (idx <= m) {
                        if (!cnt[1 - more].count(idx)) {
                            res++;
                            a[i] = idx;
                            c[more]--;
                            c[1 - more]++;
                            idx += 2;
                            ok = true;
                            break;
                        } else {
                            idx += 2;
                        }
                    }
                    if (!ok) {
                        return false;
                    }
                }
            }
        } else {
            // 如果够了，就把自己去个重
        }

        return c[more] == c[1 - more];
    };

    if (c[1] > c[0]) {
        if (my_unique(0) && change(1) && my_unique(1)) {

        } else {
            cout << "-1\n";
            return;
        }
    } else if (c[1] < c[0]) {
        if (my_unique(1) && change(0) && my_unique(0)) {

        } else {
            cout << "-1\n";
            return;
        }
    } else {
        if (my_unique(0) && my_unique(1)) {

        } else {
            cout << "-1\n";
            return;
        }
    }

    cout << res << "\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
}