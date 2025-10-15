/*
全是 P 就不可能，否则一定可能
显然至多需要操作 4 次，下面可以分别讨论答案为 0 到 4 时，图具有什么性质：
- 全 A，答案为 0
- 边缘某行/列全是 A，答案为 1
- （暗含了 4 条边缘都不是全 A，最差甚至全不是 A）经过一次变换之后，能让边缘某行/列变成全 A，答案为 2
  - 这种情况一定要先考虑把某个边缘搞成全 A，才可能次数变少
  - 本质上就是看有没有全 A 的行或者列，或者 4 个角点是否有 A
- 如果边缘有 A，则两侧扫动之后边缘就全是 A 了，再来一次就好了，答案是 3
- 这时，4 个边缘都是全 P，剩余情况答案为 4
*/

string s[N];
int n, m;

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    int tot_a = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            tot_a += (s[i][j] == 'A');
        }
    }
    if (tot_a == n * m) {
        cout << "0\n";
        return;
    }
    if (tot_a == 0) {
        cout << "MORTAL\n";
        return;
    }

    bool all_a = false;
    int cnt_a = 0;
    for (int j = 1; j <= m; j++) {
        cnt_a += (s[1][j] == 'A');
    }
    if (cnt_a == m) {
        all_a = true;
    }
    cnt_a = 0;
    for (int j = 1; j <= m; j++) {
        cnt_a += (s[n][j] == 'A');
    }
    if (cnt_a == m) {
        all_a = true;
    }
    cnt_a = 0;
    for (int i = 1; i <= n; i++) {
        cnt_a += (s[i][1] == 'A');
    }
    if (cnt_a == n) {
        all_a = true;
    }
    cnt_a = 0;
    for (int i = 1; i <= n; i++) {
        cnt_a += (s[i][m] == 'A');
    }
    if (cnt_a == n) {
        all_a = true;
    }
    if (all_a) {
        cout << "1\n";
        return;
    }

    if (s[1][1] == 'A' || s[1][m] == 'A' || s[n][1] == 'A' || s[n][m] == 'A') {
        cout << "2\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        cnt_a = 0;
        for (int j = 1; j <= m; j++) {
            cnt_a += (s[i][j] == 'A');
        }   
        if (cnt_a == m) {
            cout << "2\n";
            return;
        }
    }
    for (int j = 1; j <= m; j++) {
        cnt_a = 0;
        for (int i = 1; i <= n; i++) {
            cnt_a += (s[i][j] == 'A');
        }   
        if (cnt_a == n) {
            cout << "2\n";
            return;
        }
    }

    bool has_a = false;
    for (int i = 1; i <= n; i++) {
        if (s[i][1] == 'A' || s[i][m] == 'A') {
            has_a = true;
        }
    }
    for (int j = 1; j <= m; j++) {
        if (s[1][j] == 'A' || s[n][j] == 'A') {
            has_a = true;
        }
    }
    if (has_a) {
        cout << "3\n";
    } else {
        cout << "4\n";
    }
}
