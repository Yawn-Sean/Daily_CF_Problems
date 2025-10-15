/*
先把两个序列放到一起排个序，然后看每段 x 相等的段能有多少种变化
对于一段长为 len 的 x 相等的段，求其 y 值的排列数
mod 是输入的，可能在 mod 的意义下逆元不存在
本题比较特殊，某个 (x, y) 至多出现 2 次，所以答案是除以若干个 2!

*/

PII a[N];
LL n, mod;

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x;
        a[i].y = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i + n].x;
        a[i + n].y = i;
    }
    cin >> mod;

    sort(a + 1, a + 2 * n + 1);
    LL res = 1;

    for (int i = 1; i <= 2 * n; ) {
        int j = i;
        while (j <= 2 * n && a[j].x == a[i].x) {
            j++;
        }
        j--;
        
        unordered_map<int, int> cnt;
        int same_cnt = 0;
        for (int k = i; k <= j; k++) {
            cnt[a[k].y]++;
            if (cnt[a[k].y] == 2) {
                same_cnt++;
            }
        }

        vector<int> nums;
        for (int k = 1; k <= j - i + 1; k++) {
            nums.push_back(k);
        }
        for (int k = 0; k < j - i + 1; k++) {
            while (nums[k] % 2 == 0 && same_cnt > 0) {
                nums[k] /= 2;
                same_cnt--;
            }
            res *= nums[k];
            res %= mod;
        }
        assert(same_cnt == 0);
        i = j + 1;
    }
    cout << res << "\n";
}
