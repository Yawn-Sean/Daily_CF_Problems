/*
n = 2 时，怎么做
a[i][j] = (a[i][j - 1] * x[i] + y[i]) % m[i]，可以都暴力算出来
a[i][1]
a[i][2] = (a[i][1] * x[i] + y[i]) % m[i]
a[i][3] = (a[i][1] * x[i] * x[i] + y[i] * x[i] + y[i]) % m[i]
a[i][j] = (a[i][1] * x[i]^(j - 1) + y[i] * (1 + ... + x[i]^(j - 2))) % m[i]
两个指针扫一下，如果 a[1][p1] > a[2][p2]，是否必须 a[2][p2] 在前好呢？
我们注意到一个事情，倘若 a[i][j] < a[i][j - 1]，则无论怎么安排顺序，a[i][j - 1] 和 a[i][j] 之间总会至少贡献一个逆序
因为他总会有一个降的地方
如果是一般的序列，可能这个题就不好做了，但是现在这个序列是可以用公式生成出来的
如果 m 比较大，x 和 y 比较小，则总体上 a[i][j] 会被分割为若干单调递增的段（m 小的时候也是的，只不过可能有很多长度为 1 的段）
按照 % m，把 a[i] 序列分段，则每个段单调递增，段与段之间有可能有下降沿

n = 2, k = 2000 时，只需要所有数算出来，然后 dp 搞一下即可

考虑刚才发现的性质：倘若 a[i][j] < a[i][j - 1]，则无论怎么安排顺序，a[i][j - 1] 和 a[i][j] 之间总会至少贡献一个逆序
我们先算一下每个数列自己内部有多少这种情况，假设最多的那个有 cnt 种这种情况
由于这些下降沿之间的部分都是单调不减的，所以事实上分成了若干单调不减的段
我们把所有数列的第一段的元素都拿出来，直接暴力按照值和顺序排序
得到的这一部分肯定是各自按照顺序，且内部单调不减的
然后再处理各自的第二段...
*/

void meibao() {
    int n;
    cin >> n;
    vector<int> val(n + 1, 0), x(n + 1, 0), cnt(n + 1, 0), y(n + 1, 0), m(n + 1, 0);
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i] >> val[i] >> x[i] >> y[i] >> m[i];
        sum += cnt[i];
    }

    vector<int> p(n + 1, 0);
    vector<PII> res;
    int rd = 0;
    while (true) {
        bool all_finished = true;
        vector<PII> cur;
        for (int i = 1; i <= n; i++) {
            if (p[i] < cnt[i]) {
                all_finished = false;
                while (p[i] < cnt[i]) {
                    if (sum <= 200000)
                        cur.push_back({val[i], i});
                    p[i]++;
                    int new_val = ((LL)val[i] * x[i] + y[i]) % m[i];
                    int old_val = val[i];
                    val[i] = new_val;
                    if (p[i] < cnt[i]) {
                        if (old_val > new_val) {
                            break;
                        }
                    }
                }
            }
        }
        if (all_finished) {
            break;
        }
        rd++;
        if (sum <= 200000) {
            sort(cur.begin(), cur.end());
            for (auto p : cur) {
                res.push_back(p);
            }
        }
    }
    cout << rd - 1 << "\n";
    if (sum <= 200000) {
        for (auto p : res) {
            cout << p.x << " " << p.y << "\n";
        }
    }
}   
