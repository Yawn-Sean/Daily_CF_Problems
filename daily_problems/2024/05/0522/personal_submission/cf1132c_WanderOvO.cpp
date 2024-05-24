/*
区间加
暴力枚举去掉哪两个，假设是 [l1, r1], [l2, r2]
如果无交集，就是看 [l1, r1] 和 [l2, r2] 中各有多少 1，要去掉这些的贡献
如果有交集，则看单独部分的 1 的个数，以及交集部分的 2 的个数
*/

int T;
int n, q, a[N], l[N], r[N];
int cnt[N][3];

void solve1() {
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        cin >> l[i] >> r[i];
        a[l[i]]++;
        a[r[i] + 1]--;
    }
    int not_zero_cnt = 0;
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
        cnt[i][1] = cnt[i - 1][1];
        cnt[i][2] = cnt[i - 1][2];
        if (a[i] == 1 || a[i] == 2) {
            cnt[i][a[i]]++;
        }
        if (a[i] > 0) {
            not_zero_cnt++;
        }
    }

    int res = 0;
    for (int i = 1; i <= q; i++) {
        for (int j = i + 1; j <= q; j++) {
            if (l[i] > r[j] || l[j] > r[i]) {
                res = max(res, not_zero_cnt 
                    - (cnt[r[i]][1] - cnt[l[i] - 1][1]) 
                    - (cnt[r[j]][1] - cnt[l[j] - 1][1]));
            } else {
                int l1 = l[i], r1 = r[i], l2 = l[j], r2 = r[j];
                if (l1 > l2) {
                    swap(l1, l2);
                    swap(r1, r2);
                }
                /*
                [l1, l2 - 1]
                [l2, min(r1, r2)]
                [min(r1, r2) + 1, max(r1, r2)]
                */
                assert(l2 <= r1);
                int ans = not_zero_cnt;
                if (l1 <= l2 - 1) {
                    ans -= cnt[l2 - 1][1] - cnt[l1 - 1][1];
                }
                int rr = min(r1, r2);
                if (l2 <= rr) {
                    ans -= cnt[rr][2] - cnt[l2 - 1][2];
                }
                if (rr + 1 <= max(r1, r2)) {
                    ans -= cnt[max(r1, r2)][1] - cnt[rr][1];
                } 
                res = max(res, ans);
            }
        }
    }
    cout << res << "\n";
}        