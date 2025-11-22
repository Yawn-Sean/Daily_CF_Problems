/*
考虑枚举 a[l]，看有多少个 r 符合题意
要先知道从 b[l] 开始往右，第一个 b[i] = a[l] 的位置是谁
之后就一定保证了 a[l] 在 b[l...r] 中出现过了
我们可以用二分先找到第一个 r，使得 a[l] 在 b[l...r] 中出现过
下面考察如何计数 a[r] 不在 b[l...r] 中出现的 r 的个数
继续枚举 r，我们其实关心的是，a[r] 在 b 中出现的位置中，<= r 的最大位置是否 >= l
如果 a[r] 在 b 中出现位置中，<= r 的最大位置 >= l，说明 a[r] 在 b[l...r] 出现了
我们先把 b 中每个数出现的位置组织起来，然后预处理每个 a[i] 的在 b[1...i] 中出现的位置最大值，不妨记成 c[i]
那么枚举 l 时，先找到第一个 r，记作 min_r，然后就是关心 i in [min_r, n]，多少个 i 满足 c[i] < l
我们希望 min_r 随着 l 的枚举，是单调减小的，这样我们就方便使用树状数组去计数
对于这个事情，我们可以先随便按照一种顺序枚举 l，然后得到我们要询问的区间以及值
之后，我们把询问离线回答掉就好了
*/

struct Query {
    int min_r, val;
    
    bool operator<(const Query &o) const {
        return min_r > o.min_r;
    }    
};

Fenwick fen;
int n, a[N], b[N], c[N];
vector<vector<int>> pos(2 * N);

void solve() {   
    cin >> n;
    vector<int> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d.push_back(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        d.push_back(b[i]);
    }
    
    sort(d.begin(), d.end());
    
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin() + 1;
        b[i] = lower_bound(d.begin(), d.end(), b[i]) - d.begin() + 1;
    }
    
    for (int i = 1; i <= 2 * n; i++) {
        pos[i].clear();
    }
    
    for (int i = 1; i <= n; i++) {
        pos[b[i]].push_back(i);
    }
    
    for (int i = 1; i <= n; i++) {
        int p = upper_bound(pos[a[i]].begin(), pos[a[i]].end(), i) - pos[a[i]].begin();
        p--;
        if (p < 0) {
            c[i] = n + 1;
        } else {
            c[i] = pos[a[i]][p];
        }
    }

    vector<Query> qs;
    for (int l = n - 1; l > 0; l--) {
        int p = lower_bound(pos[a[l]].begin(), pos[a[l]].end(), l) - pos[a[l]].begin();
        if (p != pos[a[l]].size()) {
            // 存在 b[l...r]，使得 a[l] 在其中出现过
            int min_r = pos[a[l]][p];
            qs.push_back({min_r, l});
        }
    }

    sort(qs.begin(), qs.end());
    
    fen.init(2 * n + 2);
    LL res = 0;
    
    int pt = n;
    for (int i = 0; i < qs.size(); i++) {
        int min_r = qs[i].min_r, val = qs[i].val;
        while (pt >= min_r) {
            fen.modify(c[pt], 1);
            pt--;
        }
        res += fen.query(val - 1);
        res += fen.query(n + 1) - fen.query(n);
    }
    cout << res << "\n";
}
