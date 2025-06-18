/*
假如 a[i] + a[j] >= i * j * c，且 a[i] >= a[j]，且 i, j 均不为 1
考虑 a[i] + a[1] 和 i * c 的大小关系
考虑放缩：a[i] + a[i] >= a[i] + a[j] >= i * j * c >= 2 * i * c
所以 a[i] >= i * c，于是 a[i] + a[1] >= i * c
所以第一步和 a[1] 连必然比不和 a[1] 连更容易成立
连上之后，后边其实本质上还是和 1 连了
后边的按照什么顺序和 1 连呢？
由于必须要有 a[1] + a[i] >= i * c，所以 a[1] >= i * c - a[i]
按照 i * c - a[i] 升序的顺序处理
*/

LL n, c, a[N];

void meibao() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
    for (int i = 2; i <= n; i++) {
        pq.push({i * c - a[i], i});
    }
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        if (a[1] >= tp.x) {
            a[1] += a[tp.y];
        } else {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
