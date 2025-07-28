/*
有 n 个人参赛，有 i 个人之前参与过比赛，则拿到奖牌的概率是 p[i]
第 k 场比赛，有 a[k] 个之前参与过比赛的人，注意到每个人至多参与 2 次比赛
由于是求极限，所以前面的值不太重要
假如每场比赛第一次参赛的人数 >= 第二次参赛的人数，就可以一直吃老本
所以极限值的下限是 p[n / 2]，这是一定可以做到的
极限要存在，序列可以不单调，有微小的摆动
假设一共进行了 m 轮，p[i] 出现了 cnt[i] 次
res = sum(cnt[i] * p[i]) / m
保持一定的比例
怎样的比例是最优的？是否可以直接算出周期？
研究样例，发现样例 1 是 1 和 3 反复横跳，1 个 3 之后搞 3 个 1
是否一定是某两个数组合得到结果？

k = (p[i] - p[j]) / (i - j)
y = k * x + b
b = y - k * x = p[i] - k * i
令 x = n / 2，前提是这条线段确实跨过了 n / 2
*/


void meibao() {
    int n;
    cin >> n;
    vector<double> p(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    double res = p[n / 2];
    double half = n / 2.0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i < half && j > half) {
                double k = (p[i] - p[j]) / (i - j);
                double b = p[i] - k * i;
                res = max(res, k * half + b);
            }
        }
    }
    cout << setprecision(15) << res << "\n";
}
