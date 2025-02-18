/*
双指针，如果两个指针之间的 0 的数量 <= k，则可以更新一次最大长度
*/

int a[N], n, k;

void meibao() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int res = 0, l = 1, r = 1, cnt0 = 0;
    int maxl = 0, maxr = -1;
    for (r = 1; r <= n; r++) {
        cnt0 += (a[r] == 0);
        while (l <= r && cnt0 > k) {
            cnt0 -= (a[l] == 0);
            l++;
        }
        res = max(res, r - l + 1);
        if (res == r - l + 1) {
            maxl = l;
            maxr = r;
        }
    }
    cout << res << "\n";
    for (int i = 1; i < maxl; i++) {
        cout << a[i] << " ";
    }
    for (int i = maxl; i <= maxr; i++) {
        cout << "1 ";
    }
    for (int i = maxr + 1; i <= n; i++) {
        cout << a[i] << " ";
    }
}
