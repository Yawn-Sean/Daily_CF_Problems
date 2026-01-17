/*
这个题的意思是每两次洗衣服之间的时间都是随机的，并不是先随机一个周期
考虑洗了 cnt 次之后，每个位置是目标衣服的概率，第 i 个位置的概率设为 p[i]
p[i] = 1, p[j] = 0, j != i
接下来洗下一次衣服，假设这个时候选的间隔是 gap
则某个位置是目标衣服的概率会发生什么变化？
 > gap 的位置肯定不变
<= gap 的位置呢？应该是需要重新洗牌，但具体变成多少呢？
理论上应该是要搞成每个位置概率相等的
感觉应该是，new_p[j] += (p[1] + ... + p[gap]) / gap / n, if j <= gap
new_p[j] += p[j] / n，if j > gap
写代码测试了一下，这个似乎确实是正确的解法，但是现在的实现很慢，需要进行优化
这个转移能快速搞吗？

羊的思路：
如果所有操作的最大间隔 gap < i，则目标位置只可能在 i
如果所有操作的最大间隔 gap >= i，则在第一次间隔 >= i 后（不妨设这次的间隔是 g_start）
前 g_start 件衣服可以认为是等概率为目标的
之后又是一大堆打乱操作，但在前 gap 个里面，始终可以认为是等概率的
所以期望其实就是 (gap + 1) / 2
现在，我们知道了 gap < i 和 gap >= i 的时候分别的期望了，那么只要知道 gap = v 的概率，就能算了
gap = v 的概率，可以用 gap <= v 的概率和 gap <= v - 1 的概率相减计算
*/

void solve() {
    int n, start, k;
    cin >> n >> start >> k;

    auto qpow = [&] (double a, int b) -> double {
        double res = 1, base = a;
        while (b) {
            if (b & 1) {
                res = res * base;
            }
            base = base * base;
            b >>= 1;
        }
        return res;
    };

    double ans = qpow((start - 1) / (1.0 * n), k) * start;
    for (int gap = start; gap <= n; gap++) {
        ans += (qpow(gap / (1.0 * n), k) - qpow((gap - 1) / (1.0 * n), k)) * (gap + 1) / 2.0;
    }
    cout << setprecision(15) << ans << "\n";
}
