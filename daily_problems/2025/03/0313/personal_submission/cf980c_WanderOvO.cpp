/*
将 [0, 255] 的数字进行连续的分组，每组大小 <= k
给一个数列 a，a[i] 变成 a[i] 所在组的最小数字，求能变成的最小的字典序的序列
0 的那个组分多大？分 [0, k - 1] 就最好吗？
如果前面分得更小，后边的最小值会更小，但是可能会覆盖不到某些值
字典序有贪心的性质，所以还是得从序列中从前往后贪心去搞
从前往后看 a[i]，看在保证前面的取的最小值不变的情况下，看现在的 a[i] 最小能取到多少
a[1] 怎么办？直接取 [max(a[1] - k + 1, 0), a[1]] 即可
a[2] 怎么办？看 a[2] 是否已经被划到某个分区里了
- 如果在，能否调整已有的分区使之左端点更小呢？事实上是一定不能的，因为前面的分区的右端点都是已有的点，已经尽力了，所以什么事情都不用干
- 如果不在，则为其划定分区，首先分区左端点一定 >= max(0, a[i] - k + 1)
  此外，还需要关心其左边那个线段的右端点，假如那个线段没分配满且可以延伸到 a[i]，就延伸
  假如不能延申到，则左端点还需要 >= 右端点 + 1
*/

int n, k, a[N], vis[N];

void meibao() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    #ifdef rs
    #undef rs
    #endif

    set<int> rs;
    vector<PII> segs;
    for (int i = 1; i <= n; i++) {
        if (!vis[a[i]]) {
            int left = max(0, a[i] - k + 1);
            auto pos = rs.lower_bound(a[i]);
            bool can_borrow = false;
            if (pos != rs.begin()) {
                pos = prev(pos);
                int rr = *pos;
                left = max(left, rr + 1);
                for (int j = 0; j < segs.size(); j++) {
                    if (segs[j].y == rr) {
                        if (a[i] - segs[j].x + 1 <= k) {
                            can_borrow = true;
                            rs.erase(segs[j].y);
                            left = segs[j].y;
                            segs[j].y = a[i];
                            break;
                        }
                    }
                }
            } 
            for (int j = left; j <= a[i]; j++) {
                vis[j] = true;
            }
            if (!can_borrow) {
                segs.push_back({left, a[i]});
            }
            rs.insert(a[i]);
        } else {
            
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < segs.size(); j++) {
            if (a[i] >= segs[j].x && a[i] <= segs[j].y) {
                cout << segs[j].x << " ";
            }
        }
    }
}
