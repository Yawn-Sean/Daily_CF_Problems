/*
构造一个排列，使得其最长上升子序列和最长下降子序列的长度之和最小
把 1 2 ... n 拆成 cnt 段，则每段至多 (n + cnt - 1) / cnt 个数
段内上升，长度为 (n + cnt - 1) / cnt
段间下降，长度为 cnt
最小化 cnt + (n + cnt - 1) / cnt
*/

int n;

void meibao() {
    cin >> n;
    int target_seg_cnt = n, res = 2 * n + 1;
    for (int seg_cnt = 1; seg_cnt <= n; seg_cnt++) {
        int seg_len = (n + seg_cnt - 1) / seg_cnt;
        if (seg_cnt + seg_len < res) {
            res = seg_cnt + seg_len;
            target_seg_cnt = seg_cnt;
        }
    }
    int len = n / target_seg_cnt;
    for (int i = 1; i <= target_seg_cnt; i++) {
        if (n % len != 0) {
            for (int j = n - len; j <= n; j++) {
                cout << j << " ";
            }
            n -= len + 1;
        } else {
            for (int j = n - len + 1; j <= n; j++) {
                cout << j << " ";
            }
            n -= len;
        }
    }
    assert(n == 0);
}
