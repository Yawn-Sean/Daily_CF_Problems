/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-05 19:46 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector a(n + 1, 0), idx(n + 1, 0);
    int ans = 0x3f3f3f3f, maxa = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        ans = min(a[i], ans);
        idx[i] = i;
    }
    if (n == 1) {
        cout << a[1] + 1 << "\n";
        return 0;
    }
    sort(idx.begin() + 1, idx.begin() + n + 1, [&] (int x, int y) {return a[x] > a[y];});
    set<int> s;
    s.insert(0);
    s.insert(n + 1);
    int now = 1;
    vector cnt(n + 1, 0);
    cnt[n] = 1;
    vector tr(n + 1, 0);
    auto lowbit = [&] (int x) -> int {
        return x & -x;
    };
    auto query = [&] (int x) -> int {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    };
    auto add = [&] (int x) {
        for (int i = x; i <= n; i += lowbit(i)) tr[i] ++;
    };
    for (int i = 1; i <= n; i ++) {
        s.insert(idx[i]);
        auto big = s.upper_bound(idx[i]);
        auto small = s.lower_bound(idx[i]);
        small --;
        cnt[*big - *small - 1] --;
        now --;
        int len = 0;
        if (*big - 1 != idx[i]) {
            cnt[*big - idx[i] - 1] ++;
            now ++; 
        }
        if (*small + 1 != idx[i]) {
            cnt[idx[i] - *small - 1] ++;
            now ++;
        }
        add(idx[i]);
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (query(mid) == mid) l = mid;
            else r = mid - 1;
        }
        int sl, sr = n, beg;
        if (l == n) {
            break;
        }
        if (query(l) == l) {
            sl = l + 1;
            beg = l + 1;
        } else {
            sl = l;
            beg = l;
        }
        while (sl < sr) {
            int mid = sl + sr + 1 >> 1;
            if (query(mid) - query(beg) == 0) sl = mid;
            else sr = mid - 1;
        }
        len = sl - beg + 1;
        // debug("cnt[len]:", cnt[len], "now:", now);
        if (cnt[len] == now) {
            if (maxa <= now) {
                maxa = now;
                ans = a[idx[i + 1]] + 1;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
