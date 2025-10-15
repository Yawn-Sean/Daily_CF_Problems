/*
从高位往低位贪心
如果有多个入度为 0 的
- 假如该 V 拿，则肯定优先拿值最大的，因为拿其他的肯定不会更优
- 假如该 P 拿，则肯定优先拿值最小的，因为拿其他的也肯定不会更优
哪些数可以删除呢？假如一个数并不是其上面 3 个元素的唯一支撑，则其可以被删除。
删除之后怎么动态维护可删除数的集合？
对于该元素上边的，删除该元素不影响上面的元素是不是上上层元素的唯一支撑；
对于同层左右两边的元素，影响其是否会变成上层的唯一支撑；
对于下一层的元素，影响其是否还在支撑着东西，可能会变得无需支撑以至于可以被删除
只需要检查该元素周围的一些元素
*/

int m;
map<PLL, LL> p_vals;
PLL ps[N];
set<LL> s;
bool deleted[N];

int get_support_cnt(PLL p) {
    int cnt = 0;
    for (int i = -1; i <= 1; i++) {
        PLL bound;
        bound.x = p.x + i;
        bound.y = p.y - 1;
        if (p_vals.count(bound) && !deleted[p_vals[bound]]) {
            cnt++;
        }
    }
    return cnt;
}

// 检查 p 是否为上面某个元素的唯一支撑
bool check(PLL p) {
    for (int i = -1; i <= 1; i++) {
        PLL upper;
        upper.x = p.x + i;
        upper.y = p.y + 1;
        if (p_vals.count(upper) && !deleted[p_vals[upper]]) {
            int cnt = get_support_cnt(upper);
            assert(cnt >= 1);
            if (cnt == 1)
                return false;
        }
    }
    return true;
}

void meibao() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        LL x, y;
        cin >> x >> y;
        p_vals[{x, y}] = i;
        ps[i] = {x, y};
    }
    
    for (auto &p : p_vals) {
        if (check(p.x)) {
            s.insert(p.y);
        }
    }

    LL res = 0;
    int mod = 1e9 + 9;
    for (int rd = 0; rd < m; rd++) {
        PLL del_p;
        LL val;
        if (rd % 2 == 0) {
            val = *s.rbegin();
        } else {
            val = *s.begin();
        }
        res = m * res + val;
        res %= mod;
        del_p = ps[val];
        s.erase(val);
        deleted[val] = true; 

        // 下一层是否不是唯一支撑
        for (int i = -1; i <= 1; i++) {
            LL x = del_p.x + i, y = del_p.y - 1;
            PLL p = {x, y};
            if (p_vals.count(p) && !deleted[p_vals[p]] && check(p)) {
                s.insert(p_vals[p]);
            }
        }

        // 同层是否变成上面某元素的唯一支撑
        PLL l = {del_p.x - 1, del_p.y}, r = {del_p.x + 1, del_p.y};
        if (p_vals.count(l) && !deleted[p_vals[l]] && !check(l)) {
            s.erase(p_vals[l]);
        }
        if (p_vals.count(r) && !deleted[p_vals[r]] && !check(r)) {
            s.erase(p_vals[r]);
        }
        l = {del_p.x - 2, del_p.y}, r = {del_p.x + 2, del_p.y};
        if (p_vals.count(l) && !deleted[p_vals[l]] && !check(l)) {
            s.erase(p_vals[l]);
        }
        if (p_vals.count(r) && !deleted[p_vals[r]] && !check(r)) {
            s.erase(p_vals[r]);
        }
    }

    cout << res << "\n";
}
