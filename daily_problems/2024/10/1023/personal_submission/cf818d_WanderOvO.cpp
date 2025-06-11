/*
选一个颜色 B，使得 cntB[i] >= cntA[i] 恒成立
显然只能选第一个 A 颜色出现前的那些颜色
map<int, int> color_cnt
map<int, set<int>> cnt_colors
bool valid[N]
valid[i] 表示颜色 i 是合法的
最开始，第一个 A 前所有颜色都是合法的，并统计每个颜色的次数以及每个次数的颜色有哪些
每遇到一次 A，就增加 A，然后把 < A 次数集合里面的颜色都设成 invalid，以后也不管他们了
*/

map<int, int> color_cnt;
map<int, set<int>> cnt_colors;
bool valid[N];
int n, A, c[N];

void meibao() {
    cin >> n >> A;
    int first_A = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        if (c[i] == A && first_A == 0) {
            first_A = i;
        }
    }
    if (first_A == 0) {
        if (A == 1) {
            cout << "2\n";
        } else {
            cout << "1\n";
        }
        return;
    }

    memset(valid, 0, sizeof valid);
    set<int> initial_valid;
    for (int i = 1; i < first_A; i++) {
        valid[c[i]] = true;
        color_cnt[c[i]] = 0;
        initial_valid.insert(c[i]);
    }
    cnt_colors[0] = initial_valid;
    int cur_A_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i] != A) {
            if (valid[c[i]]) {
                color_cnt[c[i]]++;
                int old_cnt = color_cnt[c[i]] - 1;
                cnt_colors[old_cnt].erase(c[i]);
                cnt_colors[old_cnt + 1].insert(c[i]);
            }
        } else {
            cur_A_cnt++;
            if (cnt_colors.count(cur_A_cnt - 1)) {
                for (auto color : cnt_colors[cur_A_cnt - 1]) {
                    valid[color] = false;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (c[i] != A && valid[c[i]]) {
            if (color_cnt[c[i]] >= cur_A_cnt) {
                cout << c[i] << "\n";
                return;
            }
        }
    }
    cout << "-1\n";
}    
