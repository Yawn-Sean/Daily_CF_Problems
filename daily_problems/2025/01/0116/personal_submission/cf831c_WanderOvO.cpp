/*
n <= 2000，a 的范围也比较小
-5 0 0 20
打分者打的分数是按照时间顺序给出的，所以可以前缀和处理，设为 s[i]
对于 b 中每个数，枚举其到底是从哪个 s[i] 得到的，即 b[j] = initial_value + s[i]
这样就得到了所有可能的初始值的集合，规模为 4e6
枚举初始值，然后按照顺序应用前缀和，看能不能完全覆盖 b 中所有的数，复杂度还是炸的，吗？

羊神提示：可能的答案并不多
事实上，考虑 initial_value = b[j] - s[i]，我们真的要枚举 j 吗？并不是，只需要考虑第一个 b[1] 即可
所有的 b[1] - s[i] 就是所有可能的 initial_value，一定是这样的
*/

LL k, n, a[N], b[N], s[N];

void meibao() {
    cin >> k >> n;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    set<LL> initial_value;
    for (int i = 1; i <= k; i++) {
        initial_value.insert(b[1] - s[i]);
    }
    LL res = 0;
    for (auto value : initial_value) {
        set<LL> sb;
        for (int i = 1; i <= k; i++) {
            sb.insert(value + s[i]);
        }
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (!sb.count(b[i])) {
                ok = false;
            }
        }
        if (ok) {
            res++;
        }
    }
    cout << res << "\n";
}
