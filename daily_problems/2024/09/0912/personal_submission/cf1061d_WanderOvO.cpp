/*
本质上就是对电视节目进行分组，每组都不冲突，然后每组用一个电视去看，直到看完
不冲突的两个组未必需要合并，因为可能中间等待的时间太长
[l1, r1] 和 [l2, r2] 两个节目，假设不冲突，则一台电视直接看下来是 x + y * (r2 - l1)
重新租是 2 * x + y * (r2 - l2 + r1 - l1)
代价差值是 y * (l2 - r1) - x，如果 > 0 则重新租更好，否则留着更好
显然所有的 (r[i] - l[i]) * y 是不可避免的，我们先都算出来
我们把线段按照左端点排个序，则看到第 i 个节目时，所有比他早开始的节目都看了
从左往右遍历，每次考虑一条新线段，先考虑之前已经用电视机看的线段，找最晚的那个，算一下代价，和 x 比一下看哪个好
维护一个多重集合，里面存的是目前租了还没还回去的电视机的上次使用完成的时间，就可以二分找到结束时间刚好比自己早的
*/

int T;
LL n, x, y;
PLL segs[N];

bool cmp(const PLL &o1, const PLL &o2) {
    return o1.x < o2.x;
}

void solve1() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> segs[i].x >> segs[i].y;
    }
    sort(segs + 1, segs + n + 1, cmp);
    multiset<LL> st;
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        res += (segs[i].y - segs[i].x) * y % MOD1;
        res %= MOD1;
        auto it = st.lower_bound(segs[i].x);    
        if (it != st.begin()) {
            it = prev(it);
            LL latest = *it;
            assert(latest < segs[i].x);
            if ((segs[i].x - latest) * y < x) {
                res += (segs[i].x - latest) * y % MOD1;
                st.erase(it);
                st.insert(segs[i].y);
            } else {
                res += x;
                st.insert(segs[i].y);
            }
        } else {
            res += x;
            st.insert(segs[i].y);
        }
        res %= MOD1;
    }
    cout << res % MOD1 << "\n";
}                                                                                                                  
