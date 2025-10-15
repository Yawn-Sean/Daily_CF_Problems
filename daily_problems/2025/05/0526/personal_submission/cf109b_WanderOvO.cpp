/*
1e9 以内的幸运数很少，只有 1022 个，直接进行一个打表
不妨枚举连续的 k 个幸运数字，然后算有多少个对应的区间
*/

int nums[N]; // 存储打表结果
int cnt = 1022;
LL pl, pr, vl, vr, k;

void meibao() {
    cin >> pl >> pr >> vl >> vr >> k;
    int p1 = 0, p2 = k - 1;
    LL res = 0;
    while (p2 < cnt) {
        LL l = nums[p1], r = nums[p2];
        LL last_l, next_r;
        if (p1 == 0) {
            last_l = 0;
        } else {
            last_l = nums[p1 - 1];
        }
        if (p2 + 1 < cnt) {
            next_r = nums[p2 + 1];
        } else {
            next_r = INFLL;
        }

        // 先不算端点的情况
        LL cnt1 = 0, cnt2 = 0;
        cnt1 = max(0LL, min(l - 1, pr) - max(pl, last_l + 1) + 1);
        cnt2 = max(0LL, min(vr, next_r - 1) - max(vl, r + 1) + 1);
        res += cnt1 * cnt2;

        cnt1 = max(0LL, min(l - 1, vr) - max(vl, last_l + 1) + 1);
        cnt2 = max(0LL, min(pr, next_r - 1) - max(pl, r + 1) + 1);
        res += cnt1 * cnt2;
       
        if (l <= pr && l >= pl) {
            res += max(0LL, min(vr, next_r - 1) - max(vl, r + 1) + 1);
        }

        if (r <= pr && r >= pl) {
            res += max(0LL, min(l - 1, vr) - max(vl, last_l + 1) + 1);
        }

        if (l <= vr && l >= vl) {
            res += max(0LL, min(pr, next_r - 1) - max(pl, r + 1) + 1);
        }

        if (r <= vr && r >= vl) {
            res += max(0LL, min(l - 1, pr) - max(pl, last_l + 1) + 1);
        }

        if (pl <= l && l <= pr && vl <= r && r <= vr) {
            res++;
        }
        if (vl <= l && l <= vr && pl <= r && r <= pr) {
            if (l != r) {
                res++;
            }
        }

        p1++;
        p2++;
    } 
    // cout << res << "\n";
    double ans = (1.0 * res) / ((pr - pl + 1) * (vr - vl + 1));
    cout << setprecision(15) << ans << "\n";
}  
