LL n, a[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int res = 1;
    for (int i = 1; i <= n; ) {
        int j = i;
        while (j <= n && a[j] == -1) {
            j++;
        }

        // j = n + 1 或 a[j] != -1
        if (j == n + 1) {
            break;
        }

        // 找到了第一个不是 -1 的数
        LL first_val = a[j], first_pos = j;

        // 尝试找第 2 个非 -1 的数
        j++;
        while (j <= n && a[j] == -1) {
            j++;
        }

        // j = n + 1 或 a[j] != -1
        if (j == n + 1) {
            break;
        }

        // a[j] 是遇到的第二个不是 -1 的数，计算公差，公差不是整数必须新开一个数列
        assert(a[j] != -1);
        if ((a[j] - first_val) % (j - first_pos) != 0) {
            res++;
            i = j;
            continue;
        }

        // 计算公差，并根据公差不同分类讨论
        LL d = (a[j] - first_val) / (j - first_pos);
        if (d == 0) {
            // -1 和相等的都可以加进来
            j++;
            while (j <= n && (a[j] == -1 || a[j] == first_val)) {
                j++;
            }
            if (j == n + 1) {
                break;
            }
            res++;
            i = j;
        } else if (d > 0) {
            // 如果前面根本不允许递增，那就只能新开了
            LL val = first_val - (first_pos - i) * d;
            if (val <= 0) {
                res++;
                i = j;
            } else {
                j++;
                while (j <= n) {
                    LL target_val = first_val + (j - first_pos) * d;
                    if (a[j] != -1 && a[j] != target_val) {
                        break;
                    }
                    j++;
                }
                if (j == n + 1) {
                    break;
                }
                res++;
                i = j;
            }
        } else {
            // d < 0，那么前面的 -1 一定都是可以的，接下来只要往后遍历到 <= 0 即可
            j++;
            assert(first_val - (first_pos - i) * d > 0);
            while (j <= n) {
                LL target_val = first_val + (j - first_pos) * d;
                if (target_val <= 0) {
                    break;
                }
                if (a[j] != -1 && a[j] != target_val) {
                    break;
                }
                j++;
            }
            if (j == n + 1) {
                break;
            }
            res++;
            i = j;
        }
    }
    cout << res << "\n";
}
