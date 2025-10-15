/*
每个探头读的肯定是连续的位置
如果钦定每个探头到底读哪个区间里的点，那么每个探头至多转向 1 次
假如要读 pos，有两个探头分别在 p1, p2，pos < p1 < p2，p1 读是否一定更优？
是的，因为如果这个位置钦定给 p2 了，p1 无论往左还是往右，都会走无用的路
因此，每个点在最优的情况下只会被其左右两边最近的探头中的一个读
考虑二分最小时间，然后判断是否可行
如何判断？先从最小的探头开始看，其肯定要先把左边的都搞了，然后尽力读右边的
这样只要前一个探头读完了，下一个探头要读的左端点就确定了
有两种读法，先左后右，或先右后左，都要试一下
*/

LL n, m, h[N], p[N];

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
    }

    LL l = 0, r = 3e10, mid;

    auto check = [&] (LL ans) -> bool {
        int left_p = 1;
        for (int i = 1; i <= n; i++) {
            if (left_p > m) {
                return true;
            }

            LL left_time = ans;
            LL last_pos = h[i];

            int left_first_p = left_p, right_first_p = left_p;
            
            // 先左后右
            if (p[left_first_p] < h[i]) {
                if (left_time >= h[i] - p[left_first_p]) {
                    left_time -= h[i] - p[left_first_p];
                    last_pos = p[left_first_p];
                    left_first_p++;
                } else {
                    return false;
                }
            }

            while (left_first_p <= m && left_time >= p[left_first_p] - last_pos) {
                left_time -= p[left_first_p] - last_pos;
                last_pos = p[left_first_p];
                left_first_p++;
            }

            // 先右后左
            left_time = ans;
            last_pos = h[i];
            if (p[left_p] < h[i] && left_time < h[i] - p[left_p]) {
                return false;
            }

            if (p[left_p] >= h[i]) {
                right_first_p = left_p;
                while (right_first_p <= m && left_time >= p[right_first_p] - last_pos) {
                    left_time -= p[right_first_p] - last_pos;
                    last_pos = p[right_first_p];
                    right_first_p++;
                }
            } else {
                right_first_p = upper_bound(p + 1, p + m + 1, h[i]) - p;
                while (right_first_p <= m) {
                    if (p[right_first_p] - h[i] + p[right_first_p] - p[left_p] <= left_time) {
                        right_first_p++;
                    } else {
                        break;
                    }
                }
            }

            left_p = max(left_first_p, right_first_p);
        }

        return left_p > m;
    };

    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (check(l)) {
        cout << l << "\n";
    } else {
        cout << r << "\n";
    }
}
