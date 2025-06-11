/*
给一个排列，删除一个最小的数，使得满足 a[i] > a[j](1 <= j < i) 的 i 数量最多
维护每个数左边有多少比自己大的，以及左边比自己大的数里面，最大的那个是多少
然后从左到右枚举 a[i]，看删除之后会带来多大的收益
枚举到 a[i] 时
- 看 [1, i - 1] + [i + 1, n] 中有多少本来就行的
- 看 [i + 1, n] 中有多少左边仅有一个比自己大，且恰好是 a[i] 的
*/

int T;
int a[N], n, bigger_cnt[N], biggest[N];
BIT bit;

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bit.init(n);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        bigger_cnt[i] = i - 1 - bit.query(a[i]);
        if (mx > a[i]) {
            biggest[i] = mx;
        }
        mx = max(mx, a[i]);
        bit.add(a[i], 1);
    }
    int zero_bigger_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (bigger_cnt[i] == 0) {
            zero_bigger_cnt++;
        }
    }
    int maxres = -1, min_num = n + 1;
    // 后缀中，左边仅有一个比自己大的数，且那个数为 biggest[i]
    map<int, int> biggest_cnt;
    for (int i = 1; i <= n; i++) {
        if (biggest[i] != 0 && bigger_cnt[i] == 1) {
            biggest_cnt[biggest[i]]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        int ans = zero_bigger_cnt + biggest_cnt[a[i]] - (bigger_cnt[i] == 0);
        // cout << a[i] << " " << ans << "\n";
        if (biggest[i] != 0 && bigger_cnt[i] == 1) {
            biggest_cnt[biggest[i]]--;
        }
        if (ans > maxres) {
            maxres = ans;
            min_num = a[i];
        } else if (ans == maxres) {
            min_num = min(min_num, a[i]);
        }
    }
    cout << min_num << "\n";
}        