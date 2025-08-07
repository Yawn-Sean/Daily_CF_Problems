/*
记录每个点的横纵坐标以及初始 id
- 按照 x 排序，看一下同行被打的
- 按照 y 排序，看一下同列被打的
- 按照 x + y 排序，看一下从左上到右下的线上被打的
- 按照 x - y 排序，看一下从左下到右上的线上被打的
*/

int n, m;
int x[N], y[N], order[N], cnt[N];

bool cmp1(const int &o1, const int &o2) {
    if (x[o1] == x[o2]) return y[o1] < y[o2];
    return x[o1] < x[o2];
}

bool cmp2(const int &o1, const int &o2) {
    if (y[o1] == y[o2]) return x[o1] < x[o2];
    return y[o1] < y[o2];
}

bool cmp3(const int &o1, const int &o2) {
    if (x[o1] + y[o1] == x[o2] + y[o2]) return x[o1] < x[o2];
    return x[o1] + y[o1] < x[o2] + y[o2];
}

bool cmp4(const int &o1, const int &o2) {
    if (x[o1] - y[o1] == x[o2] - y[o2]) return x[o1] < x[o2];
    return x[o1] - y[o1] < x[o2] - y[o2];
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 1; i <= m; i++) {
        order[i] = i;
    }

    sort(order + 1, order + m + 1, cmp1);
    for (int i = 1; i <= m; i++) {
        if (i - 1 > 0 && x[order[i]] == x[order[i - 1]]) {
            cnt[order[i]]++;
        }
        if (i + 1 <= m && x[order[i]] == x[order[i + 1]]) {
            cnt[order[i]]++;
        }
    }

    sort(order + 1, order + m + 1, cmp2);
    for (int i = 1; i <= m; i++) {
        if (i - 1 > 0 && y[order[i]] == y[order[i - 1]]) {
            cnt[order[i]]++;
        }
        if (i + 1 <= m && y[order[i]] == y[order[i + 1]]) {
            cnt[order[i]]++;
        }
    }

    sort(order + 1, order + m + 1, cmp3);
    for (int i = 1; i <= m; i++) {
        if (i - 1 > 0 && x[order[i]] + y[order[i]] == x[order[i - 1]] + y[order[i - 1]]) {
            cnt[order[i]]++;
        }
        if (i + 1 <= m && x[order[i]] + y[order[i]] == x[order[i + 1]] + y[order[i + 1]]) {
            cnt[order[i]]++;
        }
    }

    sort(order + 1, order + m + 1, cmp4);
    for (int i = 1; i <= m; i++) {
        if (i - 1 > 0 && x[order[i]] - y[order[i]] == x[order[i - 1]] - y[order[i - 1]]) {
            cnt[order[i]]++;
        }
        if (i + 1 <= m && x[order[i]] - y[order[i]] == x[order[i + 1]] - y[order[i + 1]]) {
            cnt[order[i]]++;
        }
    }

    int res[9] = {0};
    for (int i = 1; i <= m; i++) {
        res[cnt[i]]++;
    }

    for (int i = 0; i <= 8; i++) {
        cout << res[i] << " ";
    }
}
