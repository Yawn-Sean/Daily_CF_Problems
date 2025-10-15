/*
注意先或后与
我或的时候怎么知道怎样能让和更小呢？是不是还是得枚举或谁，然后看与的结果
预处理所有的 a[i] - (a[i] & y)，与的时候要选一个 a[i] - (a[i] & y) 最小的，即减小最小的
枚举 a[i] |= x，则需要先删掉原来爱的 a[i] - (a[i] & y)，再加回去一个新的，求一下最小值，顺便维护一下和
把所有和的最小值作为答案即可
*/

LL n, x, y, a[N];

void meibao() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<LL, LL> cnt;
    LL sum = 0;
    LL res = 1e18;
    for (int i = 1; i <= n; i++) {
        cnt[a[i] - (a[i] & y)]++;
        sum += a[i];
    }

    for (int i = 1; i <= n; i++) {
        cnt[a[i] - (a[i] & y)]--;
        if (cnt[a[i] - (a[i] & y)] == 0) {
            cnt.erase(a[i] - (a[i] & y));
        }

        LL new_val = (a[i] | x);
        cnt[new_val - (new_val & y)]++;

        LL ans = sum - a[i] + new_val;
        auto mn = *cnt.begin();
        ans -= mn.first;
        res = min(res, ans);
        
        cnt[new_val - (new_val & y)]--;
        if (cnt[new_val - (new_val & y)] == 0) {
            cnt.erase(new_val - (new_val & y));
        }

        cnt[a[i] - (a[i] & y)]++;
    }

    cout << res << "\n";
}   
