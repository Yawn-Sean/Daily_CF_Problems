/*
枚举删掉哪个矩形，然后算横坐标和纵坐标的交集
*/

int T;
LL n;
PLL horizontal_lines[N], vertical_lines[N];
PLL pre_horizontal[N], suf_horizontal[N], pre_vertical[N], suf_vertical[N];

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        LL x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        horizontal_lines[i] = {x1, x2};
        vertical_lines[i] = {y1, y2};
    }
    
    pre_horizontal[0] = {-INF, INF};
    pre_vertical[0] = {-INF, INF};
    suf_horizontal[n + 1] = {-INF, INF};
    suf_vertical[n + 1] = {-INF, INF};
    for (int i = 1; i <= n; i++) {
        pre_horizontal[i].x = max(pre_horizontal[i - 1].x, horizontal_lines[i].x);
        pre_horizontal[i].y = min(pre_horizontal[i - 1].y, horizontal_lines[i].y);
    }
    for (int i = 1; i <= n; i++) {
        pre_vertical[i].x = max(pre_vertical[i - 1].x, vertical_lines[i].x);
        pre_vertical[i].y = min(pre_vertical[i - 1].y, vertical_lines[i].y);
    }
    for (int i = n; i > 0; i--) {
        suf_horizontal[i].x = max(suf_horizontal[i + 1].x, horizontal_lines[i].x);
        suf_horizontal[i].y = min(suf_horizontal[i + 1].y, horizontal_lines[i].y);
    }
    for (int i = n; i > 0; i--) {
        suf_vertical[i].x = max(suf_vertical[i + 1].x, vertical_lines[i].x);
        suf_vertical[i].y = min(suf_vertical[i + 1].y, vertical_lines[i].y);
    }

    // 删除哪个矩形
    for (int i = 1; i <= n; i++) {
        LL x1, y1, x2, y2;
        x1 = max(pre_horizontal[i - 1].x, suf_horizontal[i + 1].x);
        x2 = min(pre_horizontal[i - 1].y, suf_horizontal[i + 1].y);
        y1 = max(pre_vertical[i - 1].x, suf_vertical[i + 1].x);
        y2 = min(pre_vertical[i - 1].y, suf_vertical[i + 1].y);
        if (x1 <= x2 && y1 <= y2) {
            cout << x1 << " " << y1 << "\n";
            return;
        }
    }
}     