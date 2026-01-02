/*
只需要关心 a[i] != b[i] 的那些数
先不管最优，先看一下如何得到一种可行的方式吧
我们考虑每对 (a[i], b[i])
交换会带来什么
我们考虑 a[i] 在 a 中出现次数，以及 b[i] 在 b 中出现次数
交换会导致
cnt_a[a[i]]--, cnt_a[b[i]]++
cnt_b[b[i]]--, cnt_b[a[i]]++
如果交换之前 cnt_a[a[i]] > 1, cnt_a[b[i]] = 0，则这个交换对 a 来说挺好的
稍等，我觉得考虑交换有点太复杂了，我们先考虑一下不变量吧
同时考虑两个数组，假如某个数出现次数 >= 3，一定是无解
如果都 <= 2，考虑某个数 val 
假如 val 的两次出现在同一个数组里，则必须恰好选一个交换
假如 val 已经分别在两个数组里了，分别在 a[i] 和 b[j]
那么要么不操作 i 和 j，要么 i 和 j 都得操作
什么时候不操作 i 和 j？
- 如果 b[i] 和 a[j] 本身也就在各自出现了一次，自然是不用换的
- 如果 b[i] 在 b 中出现了两次，则
什么时候必须都操作 i 和 j？

感觉还是有点乱，我们能不能猜一下这是一道什么题？
应该是 DP 贪心 图论三选一

看了提示，发现确实是图论题，2-SAT
我们把刚才分析出来的都不操作、都操作、选一个操作
这几个事情写成 2-SAT 中需要满足的条件，就能做了
或者，考虑并查集
我们设 i 为 i 位置不交换，i + n 为 i 位置交换
则可以连边，比如恰好有一个位置交换就是连 i -> j + n 和 i + n -> j
使用并查集合并，i 和 i + n 如果出现在同一个集合中就废了
如果合法，如何求最小交换次数？
对于每个 i，现在已知 i 和 i + n 不在同一个集合里
如果选 i，则相当于选了 i 所在的这个集合，我们要统计里面的 > n 的数有几个
如果选 i + n，则相当于选了 i + n 所在的这个集合，同样是统计 > n 的数有几个
为了防止重复计数，这里只考虑代表元就好
*/ 

struct DSU {
    int n;
    vector<int> fa;
    
    DSU(int sz) {
        n = 2 * sz;
        fa.reserve(n + 1);
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
    } 
    
    int find(int x) {
        if (x == fa[x]) {
            return x;
        }
        return fa[x] = find(fa[x]);
    }
    
    bool together(int x, int y) {
        return find(x) == find(y);
    }
    
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        fa[x] = y;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    vector<int> cnt_a(2 * n + 1, 0), cnt_b(2 * n + 1, 0);
    vector<vector<int>> pos_a(2 * n + 1), pos_b(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        cnt_a[a[i]]++;
        cnt_b[b[i]]++;
        pos_a[a[i]].push_back(i);
        pos_b[b[i]].push_back(i);
    }
    
    DSU dsu(n);
    
    for (int i = 1; i <= 2 * n; i++) {
        if (cnt_a[i] + cnt_b[i] >= 3) {
            cout << "-1\n";
            return;
        } else if (cnt_a[i] + cnt_b[i] == 2) {
            if (cnt_a[i] == 1 && cnt_b[i] == 1) {
                int p1 = pos_a[i][0], p2 = pos_b[i][0];
                dsu.merge(p1, p2);
                dsu.merge(p1 + n, p2 + n);
            } else if (cnt_a[i] == 2) {
                int p1 = pos_a[i][0], p2 = pos_a[i][1];
                dsu.merge(p1, p2 + n);
                dsu.merge(p1 + n, p2);
            } else {
                int p1 = pos_b[i][0], p2 = pos_b[i][1];
                dsu.merge(p1, p2 + n);
                dsu.merge(p1 + n, p2);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (dsu.together(i, i + n)) {
            cout << "-1\n";
            return;
        }
    }
    
    vector<vector<int>> block(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        block[dsu.find(i)].push_back(i);
    }

    int res = 0;
    vector<int> vis(2 * n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) == i) {
            vis[i] = 1;
            int cnt0 = 0, cnt1 = 0;
            for (auto v : block[i]) {
                if (v > n) {
                    cnt0++;
                }
            }
            
            int p = dsu.find(i + n);
            vis[p] = 1;
            for (auto v : block[p]) {
                if (v > n) {
                    cnt1++;
                }
            }
            
            res += min(cnt0, cnt1);
        }
    }
    
    for (int i = n + 1; i <= 2 * n; i++) {
        if (dsu.find(i) == i && !vis[i]) {
            int cnt0 = 0, cnt1 = 0;
            for (auto v : block[i]) {
                if (v > n) {
                    cnt0++;
                }
            }
            
            int p = dsu.find(i - n);
            assert(vis[p] == 0);
            for (auto v : block[p]) {
                if (v > n) {
                    cnt1++;
                }
            }
            
            res += min(cnt0, cnt1);
        }
    }
    cout << res << "\n";
}
