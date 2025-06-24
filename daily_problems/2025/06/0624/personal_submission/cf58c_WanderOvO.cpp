/*
除了回文，每一段还必须是连续的正整数
事实上，只要某一个数确定了是多少，其他的数就都确定了，要修改多少也就确定了
我们考虑在前一半中求 a[i] - i，设 b[i] = a[i] - i，则相同的 b[i] 是属于同一种连续上升序列的
但还得考虑另一半，另一半里同组的应该怎么搞？这里应该看 a[i] + i
我们要做对应，看左半边某种 a[i] - i 对应右半边哪种 a[i] + i
枚举左边的，快速统计右边要改的，然后反之，比瞎枚举一个从未出现的值肯定更好
假设左边某个 a[i] - i = val，则可以求出来左边最后一个数应该是多少，则右边第一个数是多少也知道了
从而右边的 a[i] + i 是多少也应该知道了
上面直接可以解决偶数的情况，奇数的情况只需要特判一下要不要改最中间那个就好了
注意负数，注意 1
*/

map<int, int> l, r;
int n, a[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << "0\n";
        return;
    }

    int lmax = n / 2, rmin = (n % 2 == 0 ? (n / 2 + 1) : (n / 2 + 2));
    for (int i = 1; i <= lmax; i++) {
        l[a[i] - i]++;
    }
    for (int i = rmin; i <= n; i++) {
        r[a[i] + i]++;
    }

    int res = n;
    for (auto &it : l) {
        int val = it.x, cnt1 = it.y;
        // a[lmax] 应该改成的值
        int maxval = lmax + val;
        if (maxval < n / 2) {
            continue;
        }
        // a[rmin] = a[lmax], another = a[rmin] + rmin
        int another = maxval + rmin;
        int cnt2 = 0;
        if (r.count(another)) {
            cnt2 = r[another];
        }
        int mid = 0;
        if (n % 2) {
            if (maxval + 1 != a[lmax + 1]) {
                mid = 1;
            }
        }
        res = min(res, lmax - cnt1 + (n - rmin + 1 - cnt2) + mid);
    }
    for (auto &it : r) {
        int val = it.x, cnt2 = it.y;
        // a[rmin]
        int maxval = val - rmin;
        if (maxval < n / 2) {
            continue;
        }
        // a[lmax] - lmax
        int another = maxval - lmax;
        int cnt1 = 0;
        if (l.count(another)) {
            cnt1 = l[another];
        }
        int mid = 0;
        if (n % 2) {
            if (maxval + 1 != a[rmin - 1]) {
                mid = 1;
            }
        }
        res = min(res, lmax - cnt1 + (n - rmin + 1 - cnt2) + mid);
    }
    cout << res << "\n";
}
