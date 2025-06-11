/*
a[i][j]: 上一轮 a 投 i，b 投 j，则这一轮 a 投 a[i][j]，b 投 b[i][j]
一看就感觉很有循环的感觉
(i, j) 组合一共只可能有 9 个，所以 10 轮以内必出循环
*/

int T;
LL k, a0, b0, a[4][4], b[4][4], score_a[4][4], score_b[4][4];

void solve1() {
    map<PLL, LL> state;
    cin >> k >> a0 >> b0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> b[i][j];
        }
    }
    score_a[3][2] = 1;
    score_a[2][1] = 1;
    score_a[1][3] = 1;
    score_b[2][3] = 1;
    score_b[1][2] = 1;
    score_b[3][1] = 1;
    state[mp(a0, b0)] = 1;
    int prev_a = a0, prev_b = b0;
    LL loop_start, loop_end = 1;
    state[{prev_a, prev_b}] = 1;
    while (true) {
        int ne_a = a[prev_a][prev_b];
        int ne_b = b[prev_a][prev_b];
        PII p = {ne_a, ne_b};
        if (state.count(p)) {
            loop_start = state[p];
            break;
        }
        loop_end++;
        state[p] = loop_end;
        prev_a = ne_a;
        prev_b = ne_b;
    }
    LL loop_a_score = 0, loop_b_score = 0;
    LL before_loop_a_score = 0, before_loop_b_score = 0;
    LL after_loop_a_score = 0, after_loop_b_score = 0;
    prev_a = a0, prev_b = b0;
    for (int i = 1; i < min(loop_start, k + 1); i++) {
        int ne_a = a[prev_a][prev_b];
        int ne_b = b[prev_a][prev_b];
        before_loop_a_score += score_a[prev_a][prev_b];
        before_loop_b_score += score_b[prev_a][prev_b];
        prev_a = ne_a;
        prev_b = ne_b;
    }
    if (loop_start > k) {
        cout << before_loop_a_score << " " << before_loop_b_score << "\n";
        return;
    }
    for (int i = loop_start; i <= loop_end; i++) {
        int ne_a = a[prev_a][prev_b];
        int ne_b = b[prev_a][prev_b];
        loop_a_score += score_a[prev_a][prev_b];
        loop_b_score += score_b[prev_a][prev_b];
        prev_a = ne_a;
        prev_b = ne_b;
    }
    LL period = loop_end - loop_start + 1;
    LL period_cnt = (k - loop_start + 1) / period;
    LL after_cnt = (k - loop_start + 1) % period;
    for (int i = loop_end + 1; i <= loop_end + after_cnt; i++) {
        int ne_a = a[prev_a][prev_b];
        int ne_b = b[prev_a][prev_b];
        after_loop_a_score += score_a[prev_a][prev_b];
        after_loop_b_score += score_b[prev_a][prev_b];
        prev_a = ne_a;
        prev_b = ne_b;
    }
    cout << before_loop_a_score + after_loop_a_score + period_cnt * loop_a_score << " ";
    cout << before_loop_b_score + after_loop_b_score + period_cnt * loop_b_score << "\n";
}           