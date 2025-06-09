/*
一共有 n 对括号，不是 n 个单括号
相当于构造若干个 C(cnt, 2) 相加 = k
C(cnt, 2) = cnt * (cnt - 1) / 2
n 对括号，最多能有多少嵌套关系
((((())))): 0 + 1 + 2 + 3 + 4 = 10
(((()()))): 0 + 1 + 2 + 3 + 3 = 9
所以还是全嵌套在一起个数最多
先算出来一个最深嵌套层数，再看具体怎么套的
*/


LL n, k;
 
void meibao() {
    cin >> n >> k;

    if (n * (n - 1) / 2 < k) {
        cout << "Impossible\n";
        return;
    }

    auto check = [&] (LL ans) -> bool {
        return ans * (ans - 1) / 2 <= k;
    };

    LL l = 1, r = n, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    LL max_nest_cnt = 0;
    if (check(r)) {
        max_nest_cnt = r;
    } else {
        assert(check(l));
        max_nest_cnt = l;
    }

    LL left_cnt = n - max_nest_cnt;
    LL still_need = k - max_nest_cnt * (max_nest_cnt - 1) / 2;
    map<int, int> s;
    for (int i = max_nest_cnt - 1; i > 0 && left_cnt > 0; i--) {
        while (still_need >= i) {
            s[i]++;
            still_need -= i;
            left_cnt--;
        }
    }
    assert(still_need == 0);
    while (left_cnt > 0) {
        cout << "()";
        left_cnt--;
    }

    for (int i = 1; i <= max_nest_cnt; i++) {
        cout << "(";
        if (s.count(i)) {
            for (int j = 0; j < s[i]; j++) {
                cout << "()";
            }
        }
    }
    for (int i = 1; i <= max_nest_cnt; i++) {
        cout << ")";
    }
}   
