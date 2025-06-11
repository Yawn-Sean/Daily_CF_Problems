/*
需要到终点恰好一次，且只能最后一步到，所以一定是最左边或者最右边
到了某个位置 i，然后 i + 1/i - 1 处有障碍物，所以以后只能回头走，刚才走过的都不可能是终点
这样只可能是另一边的终点
不可能两头都加，只可能在左边或者在右边加障碍物，并且只可能加 1 个障碍物
也有可能加 0 个障碍物即可
由于最后一步不可跳过，所以最后一步为 R 则只能往左边加障碍物，反之就是只能在右边加障碍物
假设就是在右边加障碍物，那么最后只能考虑左边的终点
所有往左走的操作都不受影响，但是往右走的操作可能会被跳过
右边的障碍物加的越靠左，则可能抵消掉的 R 操作就越多，有单调性，似乎可以二分！
*/

string s;
int n;

bool check(int ans) {
    if (s[n] == 'L') {
        int cur = 0;
        int min_cur = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'L') {
                cur--;
                if (cur < min_cur) {
                    min_cur = cur;
                    cnt = 1;
                } else if (cur == min_cur) {
                    cnt++;
                }
            } else {
                if (cur + 1 < ans) {
                    cur++;
                }
            }
        }
        return (min_cur < 0 && cnt == 1 && cur == min_cur);
    } else {
        int cur = 0;
        int max_cur = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'R') {
                cur++;
                if (cur > max_cur) {
                    max_cur = cur;
                    cnt = 1;
                } else if (cur == max_cur) {
                    cnt++;
                }
            } else {
                if (cur - 1 > ans) {
                    cur--;
                }
            }
        }
        return (max_cur > 0 && cnt == 1 && cur == max_cur);
    }
}

int calc(int l, int r) {
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            if (s[n] == 'L') {
                l = mid;
            } else {
                r = mid;
            }
        } else {
            if (s[n] == 'L') {
                r = mid;
            } else {
                l = mid;
            }
        }
    }
    if (s[n] == 'L') {
        if (check(r)) {
            return r;
        } else if (check(l)) {
            return l;
        } 
    } else {
        if (check(l)) {
            return -l;
        } else if (check(r)) {
            return -r;
        } 
    }
    return 0;
}

void meibao() {
    cin >> s;
    n = s.size();
    s = " " + s;
    int cur = 0, min_cur = 0, max_cur = 0, min_cnt = 0, max_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'R') {
            cur++;
        } else {
            cur--;
        }
        if (cur < min_cur) {
            min_cur = cur;
            min_cnt = 1;
        } else if (cur == min_cur) {
            min_cnt++;
        }

        if (cur > max_cur) {
            max_cur = cur;
            max_cnt = 1;
        } else if (cur == max_cur) {
            max_cnt++;
        }
    }
    if ((min_cur < 0 && min_cnt == 1 && cur == min_cur) && s[n] == 'L') {
        cout << "1\n";
        return;
    } else if ((max_cur > 0 && max_cnt == 1 && cur == max_cur) && s[n] == 'R') {
        cout << "1\n";
        return;
    }
    int res = 0;
    if (s[n] == 'L') {
        res = calc(1, 1e6 + 10);
    } else {
        res = calc(-1e6 - 10, -1);
    }
    cout << res << "\n";
}
