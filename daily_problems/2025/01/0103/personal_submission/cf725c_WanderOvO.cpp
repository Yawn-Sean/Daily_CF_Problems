/*
27 个字母，每个至少出现一次，所以恰好有一个出现了两次
一个字母不能和自己相邻，因此连续两个一样的肯定不行
其他的呢？
先找到是哪个字母重复了，假设是 ch，出现位置是 p1 和 p2
考虑两行平均分一下，就几乎相邻了
*/

string s;

void meibao() {
    cin >> s;
    set<char> st;
    char target;
    for (auto ch : s) {
        if (st.count(ch)) {
            target = ch;
            break;
        }
        st.insert(ch);
    }
    int p1 = -1, p2 = -1;
    for (int i = 0; i < 27; i++) {
        if (s[i] == target) {
            if (p1 == -1) {
                p1 = i;
            } else {
                p2 = i;
            }
        }
    }
    int len = p2 - p1;
    if (len == 1) {
        cout << "Impossible\n";
        return;
    }
    // cout << p1 << " " << p2 << "\n";

    int mid = p1 + len / 2;
    if (len % 2 == 0) {
        mid--;
    }
    int cnt1 = mid - p1 + 1, cnt2 = p2 - mid - 1;
    // cout << cnt1 << " " << cnt2 << "\n";
    char res[2][28];
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j < 13; j++) {
            res[i][j] = ' ';
        }
    }
    for (int i = cnt1 - 1, j = p1; i >= 0; i--, j++) {
        res[1][i] = s[j];
    }
    for (int i = 0, j = mid + 1; i < cnt2; i++, j++) {
        res[0][i] = s[j];
    }

    string left = s.substr(p2 + 1) + s.substr(0, p1);
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int curx = 0, cury = cnt2, direction = 0;
    int left_cnt = left.size();
    for (int i = 0; i < left_cnt; i++) {
        res[curx][cury] = left[i];
        while (true) {
            int xx = curx + dx[direction], yy = cury + dy[direction];
            if (xx > 1 || xx < 0 || yy < 0 || yy >= 13) {
                direction++;
            } else {
                break;
            }
        }
        if (i + 1 < left_cnt) {
            assert(direction < 4);
            curx += dx[direction];
            cury += dy[direction];
        }
    }

    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j < 13; j++) {
            cout << res[i][j];
        }
        cout << "\n";
    }
}
