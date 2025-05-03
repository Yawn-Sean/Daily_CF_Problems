/*
第一块怎么选？
如果右边还有比第一块的最大值严格小的数，那就得继续往右选
后边也是一样的
*/

int n, h[N], suf_min[N];

void meibao() {
    cin >> n;
    suf_min[n + 1] = INF;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for (int i = n; i > 0; i--) {
        suf_min[i] = min(suf_min[i + 1], h[i]);
    }

    int res = 0;
    int pre_max = 0;
    for (int i = 1; i <= n; i++) {
        pre_max = max(pre_max, h[i]);
        if (pre_max <= suf_min[i + 1]) {
            res++;
            pre_max = 0;
        }
    }
    cout << res << "\n";
}   
