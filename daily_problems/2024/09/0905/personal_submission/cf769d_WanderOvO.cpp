/*
假设只有 1 位需要考虑，怎么做？
假设 a[i] = 0，其实就是看前面有多少个 1，反之也是类似的
a[i] <= 1e4，能否直接两两枚举 1e4 以内的数字，看是否正好差 k 位
然后在 a 中看这俩数出现了多少次，直接配对即可
*/

int T;
int a[N], n, k;
LL cnt[N];

int lowbit(int x) {
    return x & -x;
}

int get_cnt(int x) {
    int res = 0;
    while (x > 0) {
        x -= lowbit(x);
        res++;
    }
    return res;
}

void solve1() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }    
    int mx = 1e4;
    LL res = 0;
    if (k == 0) {
        for (int i = 0; i <= mx; i++) {
            res += cnt[i] * (cnt[i] - 1) / 2;
        }
        cout << res << "\n";
        return;
    }
    for (int i = 0; i <= mx; i++) {
        for (int j = i + 1; j <= mx; j++) {
            int val = (i ^ j);
            if (get_cnt(val) == k) {
                res += cnt[i] * cnt[j];
            }
        }
    }
    cout << res << "\n";
}             
