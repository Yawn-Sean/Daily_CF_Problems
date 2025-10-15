/*
n 为偶数，则所有数出现次数必须是 4 的倍数
n 为奇数，则恰好有一个数出现次数为奇数，用于填到正中间
然后，正中间的行和列还需要 n - 1 对数，所以这个时候需要把那些出现次数 % 4 = 2 的数用掉
在都用掉之后，剩下所有的数需要被 4 整除
如果两两成对的数还没有凑完，判断对数 * 2 是否为 4 的倍数，不是的话说明凑不出来了，否则能凑出来
最后处理 4 个组合的情况
*/

int n, cnt[M], res[M][M];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n * n; i++) {
        int val;
        cin >> val;
        cnt[val]++;
    }

    if (n % 2 == 0) {
        // 必须全是 4 的倍数
        for (int i = 1; i <= 1000; i++) {
            if (cnt[i] % 4 != 0) {
                cout << "NO\n";
                return;
            }
        }

        cout << "YES\n";
        int pt = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (res[i][j] == 0) {
                    while (pt <= 1000 && cnt[pt] < 4) {
                        pt++;
                    }
                    assert(pt <= 1000);
                    cnt[pt] -= 4;
                    res[i][j] = pt;
                    res[i][n - j + 1] = pt;
                    res[n - i + 1][j] = pt;
                    res[n - i + 1][n - j + 1] = pt;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << res[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        vector<int> odd;
        for (int i = 1; i <= 1000; i++) {
            if (cnt[i] % 2) {
                odd.push_back(i);
            }
        }

        if (odd.size() != 1) {
            cout << "NO\n";
            return;
        }

        // 填正中间的
        res[(n + 1) / 2][(n + 1) / 2] = odd[0];
        cnt[odd[0]]--;

        // 使用出现次数 % 4 = 2 的数去填两两成对的
        int pt = 1;
        int filled = 0;
        for (int i = 1; i < (n + 1) / 2; i++) {
            int j = (n + 1) / 2;
            while (pt <= 1000 && cnt[pt] % 4 != 2) {
                pt++;
            }
            if (pt <= 1000) {
                filled++;
                cnt[pt] -= 2;
                res[i][j] = pt;
                res[n - i + 1][j] = pt;
            }
        }

        for (int j = 1; j < (n + 1) / 2; j++) {
            int i = (n + 1) / 2;
            while (pt <= 1000 && cnt[pt] % 4 != 2) {
                pt++;
            }
            if (pt <= 1000) {
                filled++;
                cnt[pt] -= 2;
                res[i][j] = pt;
                res[i][n - j + 1] = pt;
            }
        }

        // 两两成对的可能填完了，也可能没填完，但最终应该这部分剩下要填的位置是 4 的倍数
        if ((n - 1 - filled) * 2 % 4 != 0) {
            cout << "NO\n";
            return;
        }

        // 两两成对的部分不管填没填完，剩下的数的次数都应该是 4 的倍数
        for (int i = 1; i <= 1000; i++) {
            if (cnt[i] % 4 != 0) {
                cout << "NO\n";
                return;
            }
        }

        // 把两两成对没填完的填一下
        pt = 1;
        for (int i = 1; i < (n + 1) / 2; i++) {
            int j = (n + 1) / 2;
            if (res[i][j]) {
                continue;
            }
            while (pt <= 1000 && !cnt[pt]) {
                pt++;
            }
            if (pt <= 1000) {
                cnt[pt] -= 2;
                res[i][j] = pt;
                res[n - i + 1][j] = pt;
            }
        }

        for (int j = 1; j < (n + 1) / 2; j++) {
            int i = (n + 1) / 2;
            if (res[i][j]) {
                continue;
            }
            while (pt <= 1000 && !cnt[pt]) {
                pt++;
            }
            if (pt <= 1000) {
                cnt[pt] -= 2;
                res[i][j] = pt;
                res[i][n - j + 1] = pt;
            }
        }

        // 填剩下的 4 个一组的
        cout << "YES\n";
        pt = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (res[i][j] == 0) {
                    while (pt <= 1000 && cnt[pt] < 4) {
                        pt++;
                    }
                    assert(pt <= 1000);
                    cnt[pt] -= 4;
                    res[i][j] = pt;
                    res[i][n - j + 1] = pt;
                    res[n - i + 1][j] = pt;
                    res[n - i + 1][n - j + 1] = pt;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << res[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
