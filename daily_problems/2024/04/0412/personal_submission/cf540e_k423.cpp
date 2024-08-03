// https://codeforces.com/contest/540/submission/256185330

/* 我永远喜欢爱莉希雅♪ */
template<typename iter>
int64_t inversion_count(iter begin, iter end) {
    if (begin == end) return 0;
    auto cpy = vector(begin, end), tmp = cpy;
    begin = cpy.begin(), end = cpy.end();
    int64_t ret = 0;
    function<void(int, int)> merge = [&](int l, int r) {
        if (l == r) return;
        int mid = (l + r) / 2;
        merge(l, mid), merge(mid + 1, r);
        int i = l, j = mid + 1, k = l;
        while (i <= mid) {
            while (j <= r && begin[j] < begin[i]) tmp[k++] = begin[j++];
            ret += j - mid - 1;
            tmp[k++] = begin[i++];
        }
        while (j <= r) tmp[k++] = begin[j++];
        copy(tmp.begin() + l, tmp.begin() + r + 1, begin + l);
    };
    merge(0, end - begin - 1);
    return ret;
}

void elysia() {
    int n;
    cin >> n;
    vector<pii> p(n);
    vector<int> disc;
    for (auto &[x, y]: p) {
        cin >> x >> y;
        disc.emplace_back(x);
        disc.emplace_back(y);
    }
    ranges::sort(disc);
    disc.erase(ranges::unique(disc).begin(), disc.end());
    int m = disc.size();
    vector<int> fake(m);
    iota(itr(fake), 0);
    for (auto &[x, y]: p) {
        x = ranges::lower_bound(disc, x) - disc.begin();
        y = ranges::lower_bound(disc, y) - disc.begin();
        swap(fake[x], fake[y]);
    }
    i64 ans = 0;
    for (int i = 0; i < m; ++i) {
        int j = fake[i];
        ans += abs(disc[i] - disc[j]) - abs(i - j);
    }
    ans += inversion_count(itr(fake));
    cout << ans << endl;
}
