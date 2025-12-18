/*
什么时候无解？
没有攻击，一定无解
如果初始是 0，并且没有加，也一定无解
其他情况一定有解
 
接着考虑怎么最小化次数
注意到如果有乘法的话，31 轮左右，即最多模拟 1500 多轮，肯定能干掉对方
我们分情况讨论一下：
- 如果只有加法，如果不是最后一轮，那就先把所有加法用了，然后再 attack，接着是下一轮
  这个轮次会很多吗？
  如果完全没加法，那么是好算的
  如果有加法，假如第一轮能打 P + s，第二轮就能再打 P + 2 * s...
  这是个等差数列，目标是 1e9，所以轮数应该是开根号的
- 如果有加法有乘法，显然是先加再乘（乘 1 没用但是它依然占一轮），最后打
 
根据上面的分析，我们发现只需要直接模拟每轮的情况，注意别爆了数据范围，到了 1e9 就停下
如果发现这一轮打不死，没关系，下一轮继续努力
如果发现这一轮按照这个策略能打死了，那说明这一轮得重算一下了
如何重算？
我们知道现在的攻击力 cur_p，剩余体力 cur_h
我们关心再进行 i 轮强化操作，我们的攻击最多能到什么地步，并钦定之后只攻击，算一下回合数
我们其实就是想看，前 i 轮，用了 j 次加法(i - j 次乘法)，最多能到多少
其实还是先加后乘最后打
 
本题考察复杂度分析 + 贪心 + 模拟
*/
 
void solve() {
    LL n, p, h;
    cin >> n >> p >> h;
    vector<LL> mult, add;
    LL attack_cnt = 0;
    for (int i = 1; i <= n; i++) {
        string op;
        LL x;
        cin >> op;
        if (op == "+") {
            cin >> x;
            add.push_back(x);
        } else if (op == "*") {
            cin >> x;
            if (x > 1) {
                mult.push_back(x);
            }
        } else {
            attack_cnt++;
        }
    }
 
    // 无解的情况
    if (attack_cnt == 0 || (p == 0 && add.size() == 0)) {
        cout << "*\n";
        return;
    }
 
    sort(mult.rbegin(), mult.rend());
    sort(add.rbegin(), add.rend());
 
    // p 不会变的情况，直接算即可，注意特判最后一轮
    if (add.size() == 0 && mult.size() == 0) {
        assert(p != 0);
        LL round_cost = attack_cnt * p;
        LL need_round = (h + round_cost - 1) / round_cost;
        // 前 need_round - 1 轮必须是完整的
        LL res = (need_round - 1) * n;
        h -= round_cost * (need_round - 1);
        // 最后一轮只用攻击技能即可
        res += (h + p - 1) / p;
        cout << res << "\n";
 
        return;
    }
 
    // 需要先贪心打完若干轮，然后特殊处理最后一轮的情况
    LL res = 0;
    LL cur_p = p, cur_h = h;
    while (true) {
        LL new_p = cur_p;
        bool finished = false;
 
        for (auto v : add) {
            new_p += v;
            if (new_p >= cur_h) {
                finished = true;
                break;
            }
        }
        if (finished) {
            break;
        }
 
        for (auto v : mult) {
            new_p *= v;
            if (new_p >= cur_h) {
                finished = true;
                break;
            }
        }
        if (finished) {
            break;
        }
        
        // new_p = min(new_p, cur_h);
        if (new_p * attack_cnt >= cur_h) {
            break;
        }
 
        cur_h -= new_p * attack_cnt;
        cur_p = new_p;
        res += n;
    }
 
    LL min_final_cnt = n;
    for (int i = 0; i <= add.size(); i++) {
        for (int j = 0; j <= mult.size(); j++) {
            LL new_p = cur_p;
            for (int k = 0; k < i; k++) {
                new_p += add[k];
                new_p = min(new_p, cur_h);
            }
            for (int k = 0; k < j; k++) {
                new_p *= mult[k];
                new_p = min(new_p, cur_h);
            }
 
            if (new_p * attack_cnt >= cur_h) {
                LL need_cnt = (cur_h + new_p - 1) / new_p;
                min_final_cnt = min(min_final_cnt, need_cnt + i + j);
            }
        }
    }
    res += min_final_cnt;
    cout << res << "\n";
}
 
