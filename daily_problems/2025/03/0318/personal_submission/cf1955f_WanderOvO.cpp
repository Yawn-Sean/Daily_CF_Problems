int cnt[5];

void meibao() {
    for (int i = 1; i <= 4; i++) {  
        cin >> cnt[i];
    }

    int res = 0;
    if (cnt[4] % 2 != 0) {
        cnt[4]--;
    }

    // 有可能全是 0，不能贡献
    if (cnt[1] % 2 == cnt[2] % 2 && cnt[2] % 2 == cnt[3] % 2 && (cnt[1] + cnt[2] + cnt[3] + cnt[4] > 0)) {
        res++;
    }

    bool op = false;
    for (int i = 1; i <= 3; i++) {
        if (cnt[i] % 2) {
            cnt[i]--;
            op = true;
        }
    }

    if (cnt[1] + cnt[2] + cnt[3] + cnt[4] > 0 && op) {
        res++;
    }

    // 至此，所有数都出现偶数次
    for (int i = 1; i <= 4; i++) {
        res += cnt[i] / 2;
    }

    // 最后两个两个的删时如果确实还有数，则最后一步不能算进去
    if (cnt[1] + cnt[2] + cnt[3] + cnt[4] > 0) {
        res--;
    }
    cout << res << "\n";
}
