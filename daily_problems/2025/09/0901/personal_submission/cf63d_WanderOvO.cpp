/*
并非要求分割成矩形
本题限制了 b != d，也就是说左下或者右下角一定是有一块缺掉的
设 min_r = min(b, d)
按照 min_r 的奇偶，以及 b 和 d 的大小关系分类去填，蛇形走位分配即可

所以只要 sum(x) = a * b + c * d，就是一定有解的
*/

int a, b, c, d, n, cnt[M];
char res[M][M];

bool out_of_bound(int x, int y) {
    if (x <= min(b, d)) {
        return y > 0 && y <= a + c;
    }
    if (b > d) {
        return y > 0 && y <= a;
    } else {
        return y <= a + c && y >= a + 1;
    }
}

void color(int sx, int sy, int direction) {
    for (int idx = 1; idx <= n; idx++) {
        char ch = idx + 'a' - 1;
        while (cnt[idx] > 0) {
            res[sx][sy] = ch;
            cnt[idx]--;
            if (out_of_bound(sx, sy + direction)) {
                sy += direction;
            } else {
                sx += 1;
                direction *= -1;
            }
        }
    }
}

void meibao() {
    cin >> a >> b >> c >> d >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i];
    }

    for (int i = 1; i <= max(b, d); i++) {
        for (int j = 1; j <= a + c; j++) {
            res[i][j] = '.';
        }
    }

    int min_r = min(b, d);
    if (min_r % 2 == 0) {
        if (b > d) {
            int cur_x = 1, cur_y = 1;
            color(cur_x, cur_y, 1);
        } else {
            int cur_x = 1, cur_y = a + c;
            color(cur_x, cur_y, -1);
        }
    } else {
        if (b > d) {
            int cur_x = 1, cur_y = a + c;
            color(cur_x, cur_y, -1);
        } else {
            int cur_x = 1, cur_y = 1;
            color(cur_x, cur_y, 1);
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= max(b, d); i++) {
        for (int j = 1; j <= a + c; j++) {
            cout << res[i][j];
        }
        cout << "\n";
    }
}
