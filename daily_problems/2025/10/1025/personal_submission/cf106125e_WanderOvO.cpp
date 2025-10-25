
/*
给你一个 n 位的数组，每个数要么是 0 要么是 1，最开始全是 0
每次操作，你可以指定一个区间 [l, r]
对于 a[l...r]，每个元素有 50% 的概率被翻转
我们的目标是让 70% 以上的元素是 1
至多操作 125 次

第一次询问一定是询问 [1, n]，这样能最大限度地让 0 变成 1
我们如果每次操作的都是纯 0 或者大部分是 0 的子数组，则我们更有可能得到更多的 1
从期望来看，我们每次操作纯 0 的数组，能把一半的数变成 1
但实际操作时，未必一下子能做到这一点
然后整个数组应该是被分成很多散着的段，之后需要分别操作
每次贪心取最长的一段连续 0 操作，会不会好一些呢？
初次操作如果结果不够好，分成太多散的段了，后边的操作可能就会比较痛苦

我们考虑一个段 [l, r]，算一下它这里面 0 占的比例
倘若比例超过某个 ratio，我们就操作它，并且尽量选较长的操作
*/

int n, a[N], s[N];

void solve() {
    cin >> n;
    int rd = 125;
    int one_cnt;
    double max_r = 0.75;
    while (rd--) {
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + a[i];
        }
        int query_l = 1, query_r = n, len = 0;
        for (int l = 1; l <= n; l++) {
            for (int r = l; r <= n; r++) {
                int zero_cnt = (r - l + 1) - s[r] + s[l - 1];
                double ratio = (1.0 * zero_cnt) / (r - l + 1);
                if (ratio >= max_r) {
                    if (r - l + 1 > len) {
                        len = r - l + 1;
                        query_l = l;
                        query_r = r;
                    }
                }
            }
        }
        
        cout << query_l << " " << query_r << endl;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cin >> one_cnt;
        if (one_cnt >= 70) {
            break;
        }
    }
}
