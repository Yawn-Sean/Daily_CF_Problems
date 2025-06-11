/*
分两步，先算出来至少要买多少披萨，再算最大价值
每个披萨（不管类别）都是每块有 S 片
每个人总之就是吃 s[i] 片，所以总共就是 sum(s[i]) 片
所以最少买 min_cnt = sum(s[i]) / S 上取整个披萨
之后考虑 min_cnt 块中多少块是第一类，以及每个人吃哪一类
能否贪心吃 a[i] 和 b[i] 中较大的那个？
这样可能导致会多买一些披萨，确切来说是可能多买恰好一个披萨，考虑反悔调整
如果是把 a 反悔成 b，则优先反悔 a[i] - b[i] 比较小的，反之就是优先比较大的
是把 a 反悔成 b，还是把 b 反悔成 a 呢？两种情况都做一遍看哪个更好
如果是 a 反悔成 b，要反悔多少片呢？a 反悔成 b 说明 a 最后一张没吃完
所以把最后一张已经吃的片数反悔成 b 就行了
*/

struct Person {
    LL s, a, b;

    bool operator<(const Person &o) const {
        return a - b < (o.a - o.b);
    }
};

LL n, S;
Person persons[N];

void meibao() {
    cin >> n >> S;
    for (int i = 1; i <= n; i++) {
        cin >> persons[i].s >> persons[i].a >> persons[i].b;
    }
    sort(persons + 1, persons + n + 1);
    LL min_cnt = 0;
    for (int i = 1; i <= n; i++) {
        min_cnt += persons[i].s;
    }
    min_cnt = (min_cnt + S - 1) / S;
    LL a_slice_cnt = 0, b_slice_cnt = 0, greedy_val = 0;
    for (int i = 1; i <= n; i++) {
        if (persons[i].a > persons[i].b) {
            a_slice_cnt += persons[i].s;
            greedy_val += persons[i].s * persons[i].a;
        } else {
            b_slice_cnt += persons[i].s;
            greedy_val += persons[i].s * persons[i].b;
        }
    }
    LL cur_cnt = (a_slice_cnt + S - 1) / S + (b_slice_cnt + S - 1) / S;
    if (cur_cnt == min_cnt) {
        cout << greedy_val << "\n";
    } else {
        LL a_to_b_val = greedy_val, b_to_a_val = greedy_val;
        LL convert_cnt = a_slice_cnt % S;
        for (int i = 1; i <= n && convert_cnt > 0; i++) {
            if (persons[i].a > persons[i].b) {
                if (convert_cnt < persons[i].s) {
                    a_to_b_val -= persons[i].a * convert_cnt;
                    a_to_b_val += persons[i].b * convert_cnt;
                    convert_cnt = 0;
                } else {
                    a_to_b_val -= persons[i].a * persons[i].s;
                    a_to_b_val += persons[i].b * persons[i].s;
                    convert_cnt -= persons[i].s;
                }
            }
        }
        assert(convert_cnt == 0);
        convert_cnt = b_slice_cnt % S;
        reverse(persons + 1, persons + n + 1);
        for (int i = 1; i <= n && convert_cnt > 0; i++) {
            if (persons[i].a <= persons[i].b) {
                if (convert_cnt < persons[i].s) {
                    b_to_a_val -= persons[i].b * convert_cnt;
                    b_to_a_val += persons[i].a * convert_cnt;
                    convert_cnt = 0;
                } else {
                    b_to_a_val -= persons[i].b * persons[i].s;
                    b_to_a_val += persons[i].a * persons[i].s;
                    convert_cnt -= persons[i].s;
                }
            }
        }
        assert(convert_cnt == 0);
        cout << max(a_to_b_val, b_to_a_val) << "\n";
    }
}   
