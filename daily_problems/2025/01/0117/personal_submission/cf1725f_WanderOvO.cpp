/*
有 n 行，列数可以认为是无穷大，每行有一个线段，每次可以将一条线段向东或者向西移动 k 个单位，需要 z |= k
给定 w，要求所有操作执行完之后得到的 z = w，求所有列中至多被覆盖了多少次

注意到假如 k 的二进制位是 z 的子集，则操作时 z 就不会变了
假如给的 w 是奇数，则可以先移动 w，剩下的一直移动 1 即可，答案一定是 n
假如给的 w 不是奇数，则考虑 w 的最低非 0 二进制位，即 lowbit(w)，则 lowbit(w) 就是最小的移动单位
下面检查最小移动单位为 lowbit(w) 时，某列至多有几个线段
倘若一个段的长度 >= lowbit(w)，则说明这个段可以几乎覆盖任何一个地方（除了两端的一些边角），我们总能让这些段有交集
倘若一个段的长度 < lowbit(w)，则说明覆盖的地方断断续续的
对于 [l, r]，r - l + 1 < lowbit(w)，其可以覆盖 [l + k * lowbit(w), r + k * lowbit(w)] 的地方
画画图，考虑把所有的段平移到某个长度为 lowbit(w) 的区间内
有的段整个可以进去，有的只能进去一部分，进去一部分的可能需要分头和尾两部分去处理
如何快速去算最多重叠多少次？发现不用快，因为 lowbit(w) 的情况数太少了，所以每种情况爆算预处理即可，具体来说可以用 map 差分
map 太慢了，不如直接维护那个位置加了那个数的键值对，然后 sort 一下之后实现差分
*/

int lowbit(int x) {
    return x & -x;
}

int n, l[N], r[N], q;

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    
    int res[33] = {0};
    for (int i = 0; i < 31; i++) {
        int w = (1 << i);
        res[i] = 0;
        vector<PII> segs;
        for (int j = 1; j <= n; j++) {
            int len = r[j] - l[j] + 1;
            if (len >= w) {
                res[i]++;
            } else {
                int st = l[j] % w, ed = r[j] % w;
                segs.push_back({st, 1});
                segs.push_back({ed + 1, -1});
                if (st > ed) {
                    res[i]++;
                }
            }
        }
        int ans = res[i];
        sort(segs.begin(), segs.end());
        for (auto &it : segs) {
            int k = it.x, v = it.y;
            ans += v;
            res[i] = max(res[i], ans);
        }
    }
    
    cin >> q;
    while (q--) {
        int w;
        cin >> w;
        w = lowbit(w);
        cout << res[__lg(w)] << "\n";
    }
}
