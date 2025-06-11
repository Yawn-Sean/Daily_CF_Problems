/*
不妨先升序排序，排序不影响答案
枚举到 a[i] 时，看左边有多少 a[j] 满足 a[j] <= y <= a[i] 且 y % x == 0
转化为 [1, a[i]] 中能被 x 整除的数的个数 - [1, a[j]] 中的
[1, val] 中有 val / x 个 x 的倍数
这个事情可以二分计算出下标范围
*/

int n, a[N], x, k;

bool check_right(int l, int r) {
    return a[r] / x - (a[l] - 1) / x >= k;
}

int find_right(int pos) {
    int l = 1, r = pos, mid;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (check_right(mid, pos)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (check_right(r, pos)) {
        if (a[pos] / x - (a[r] - 1) / x == k) {
            return r;
        }
        return -1;
    } else if (check_right(l, pos)) {
        if (a[pos] / x - (a[l] - 1) / x == k) {
            return l;
        }
        return -1;
    }
    return -1;
}

bool check_left(int mid, int right, int pos) {
    int cnt1 = a[pos] / x - (a[mid] - 1) / x;
    int cnt2 = a[pos] / x - (a[right] - 1) / x;
    return cnt1 == cnt2;
}

int find_left(int right, int pos) {
    int l = 1, r = right, mid;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (check_left(mid, right, pos)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (check_left(l, right, pos)) {
        return l;
    } 
    assert(check_left(r, right, pos));
    return r;
}

void solve1() {
    cin >> n >> x >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        int right = find_right(i);
        if (right != -1) {
            int left = find_left(right, i);
            res += right - left + 1;
        }
    }
    map<int, int> cnt;
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }
    for (auto &it : cnt) {
        if (it.y > 1) {
            LL c = it.y;
            if (k == 0 && it.x % x != 0) {
                res += c * (c - 1) / 2;
            } else if (k == 1 && it.x % x == 0) {
                res += c * (c - 1) / 2;
            }
        }
    }
    cout << res << "\n";
}       
