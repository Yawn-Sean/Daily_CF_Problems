/*
x^(1 / 4) <= y <= min(x^(1 / 2), x - 1) 就够了
x = 1, 2, 3 时都不能继续操作了
x <= 1e12, n <= 1e6
每一堆每次至少变成原来的根号大小，所以每堆至多被操作 5 次就不可能继续操作了
假如只有 1 堆，怎样博弈最优？
我们可以发现其实只要考虑到 1e6 就可以了，这样 1e12 以内的数就一定都考虑到了
一个堆的情况研究明白了，接下来把所有堆拿出来看，使用 SG 定理合并即可
所以只分析出来每堆必胜还是必败是不够的，还得把 SG 函数算出来

SG(u) = mex(SG(v))，但是比较大的点有 1e3 个后继需要看
对于 1e3 范围内的 u，很好说，直接爆算就行
对于 > 1e3 的 u，开根号之后就 < 1e3 了，用两个指针卡住范围
随着 u 的变大，指针单调变化，可以通过插入数和删除数动态维护 mex

如何动态维护 mex？参考一下严格鸽的做法，用 cnt 数组维护每个数出现次数，用一个 set 维护哪些数没出现过
插入新的数时从 set 中删除掉，删除一个数的最后一次时把他插到 set 中，查 set 的最小值就是 mex
*/

int n;
LL a[N], cnt[N], sg[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    sg[1] = sg[2] = sg[3] = 0;
    set<LL> disappear;
    for (int i = 0; i <= N; i++) {
        disappear.insert(i);
    }
    LL l = 1, r = 0;
    for (int i = 4; i < N; i++) {
        for ( ; (r + 1) * (r + 1) <= i && r + 1 < i; r++) {
            cnt[sg[r + 1]]++;
            if (cnt[sg[r + 1]] == 1) {
                disappear.erase(sg[r + 1]);
            }
        }
        for ( ; l * l * l * l < i; l++) {
            cnt[sg[l]]--;
            if (cnt[sg[l]] == 0) {
                disappear.insert(sg[l]);
            }
        }
        sg[i] = *disappear.begin();
    }
    LL res = 0;
    sort(a + 1, a + n + 1);
    memset(cnt, 0, sizeof cnt);
    l = 0;
    r = 0;
    disappear.clear();
    for (int i = 0; i <= N; i++) {
        disappear.insert(i);
    }
    for (int i = 1; i <= n; i++) {
        while (l * l * l * l < a[i]) {
            cnt[sg[l]]--;
            if (cnt[sg[l]] == 0) {
                disappear.insert(sg[l]);
            }
        }
        while ((r + 1) * (r + 1) <= a[i] && r + 1 < a[i]) {
            cnt[sg[r + 1]]++;
            if (cnt[sg[r + 1]] == 1) {
                disappear.insert(sg[r + 1]);
            }
        }
        res ^= *disappear.begin();
    }
    if (res == 0) {
        cout << "Rublo\n";
    } else {
        cout << "Furlo\n";
    }
}            
