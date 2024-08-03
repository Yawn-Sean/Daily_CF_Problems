int n;

void solve() {
    cin >> n;
    vector<int> a(n * 2 - 1);
    cin >> a;
    // 偶数个负数 一定可以全变为正数
    // 奇数个负数, n为奇数, 那么可以全变成正数
    // 奇数个负数, n为偶数, 让绝对值最小的为负数
    int cnt = 0, sum = 0;
    for (auto& x : a) {
        if (x < 0) cnt ++;
        x = abs(x);
        sum += x;
    }
    
    if (cnt % 2 == 0) {
        cout << sum << endl;
        return;
    }
    if (n & 1) {
        cout << sum << endl;
        return;
    }
    sort(all(a));
    sum -= a[0] * 2;
    cout << sum << endl;
}