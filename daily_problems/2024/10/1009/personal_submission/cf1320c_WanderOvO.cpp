/*
暴力就是枚举武器、枚举防具、枚举怪兽
所有怪兽按照防御力排序，防御力相同按照攻击力排序
武器和防具也按照数值排一下序
从小到大枚举一下武器，则其可能能打败的怪兽只会在前缀里
接下来的问题就是，选什么防具，以及如何快速计算收益
使用权值树状数组，以攻击力为下标，收益为值，把怪兽插入进去
则枚举防具时，只需要查询攻击力 <= 防具防御力的树状数组怪兽的价值之和即可
但这样还是 O(nmlog(p))

羊神提示：
还是按照攻击力上升的顺序枚举武器，对于每次加入的怪兽，计算哪些防具遇到这个怪兽有收益
防具也可以按照数值排序，所以其实防具的更新也是连续的区间的更新
每次更新防具的收益之后，取最大的，然后把武器的减掉
*/

struct Monster {
    LL x, y, z;

    bool operator<(const Monster &o) const {
        if (x == o.x) {
            return y < o.y;
        }
        return x < o.x;
    }
};

LL n, m, p;
PLL weapons[N], as[N];
Monster ms[N];
SegmentTree tr;

inline bool check(LL ans, LL target) {
    return as[ans].x > target;
}

int find_pos(LL target) {
    int l = 1, r = m, mid;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (check(mid, target)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (check(l, target)) {
        return l;
    } else if (check(r, target)) {
        return r;
    }
    return 0;
}

void meibao() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        cin >> weapons[i].x >> weapons[i].y;
    }
    for (int i = 1; i <= m; i++) {
        cin >> as[i].x >> as[i].y;
    }
    for (int i = 1; i <= p; i++) {
        cin >> ms[i].x >> ms[i].y >> ms[i].z;
    }
    sort(weapons + 1, weapons + n + 1);
    sort(as + 1, as + m + 1);
    sort(ms + 1, ms + p + 1);
    int m_idx = 1;
    tr.init(m, as);
    LL res = -INFLL;
    for (int i = 1; i <= n; i++) {
        for ( ; m_idx <= p && ms[m_idx].x < weapons[i].x; m_idx++) {
            LL target = ms[m_idx].y;
            LL val = ms[m_idx].z;
            int pos = find_pos(target);
            if (pos != 0) {
                tr.add(1, m, pos, m, 1, val);
            }
        }
        res = max(res, tr.query(1, m, 1, m, 1) - weapons[i].y);
    }
    cout << res << "\n";
}  
